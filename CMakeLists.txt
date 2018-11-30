#
# Copyright 2017, Data61
# Commonwealth Scientific and Industrial Research Organisation (CSIRO)
# ABN 41 687 119 230.
#
# This software may be distributed and modified according to the terms of
# the BSD 2-Clause license. Note that NO WARRANTY is provided.
# See "LICENSE_BSD2.txt" for details.
#
# @TAG(DATA61_BSD)
#

cmake_minimum_required(VERSION 3.7.2)

include(${KERNEL_HELPERS_PATH})

add_subdirectory(apps/console_server)
add_subdirectory(apps/file_server)
add_subdirectory(apps/nethack)
add_subdirectory(apps/process_server)
add_subdirectory(apps/selfloader)
add_subdirectory(apps/snake)
add_subdirectory(apps/terminal)
add_subdirectory(apps/test_os)
add_subdirectory(apps/test_user)
add_subdirectory(apps/tetris)
add_subdirectory(apps/timer_server)
add_subdirectory(libs/libdatastruct)
add_subdirectory(libs/librefos)
add_subdirectory(libs/librefossys)
add_subdirectory(libs/libvterm)

project(refos NONE)

set(configure_string "")

#
# seL4 RefOS Applications
#
config_option(AppProcServer     APP_PROCESS_SERVER        "Enable Process Server app"               DEFAULT ON)
config_string(ProcServerMemSize PROCSERV_INITIAL_MEM_SIZE "Initial memory size of Process Server"   DEFAULT 196608 UNQUOTE)
config_string(ProcServerVSpace  PROCSERV_MAX_VSPACES      "Maximum V-Space size for Process Server" DEFAULT 64     UNQUOTE)
config_option(AppSelfLoader     APP_SELF_LOADER           "Enable Self Loader app"                  DEFAULT ON)
config_option(AppFileServer     APP_FILE_SERVER           "Enable File Server app"                  DEFAULT ON)
config_option(AppConsoleServer  APP_CONSOLE_SERVER        "Enable Console Server app"               DEFAULT ON)
config_option(AppTimerServer    APP_TIMER_SERVER          "Enable Timer Server app"                 DEFAULT ON)
config_option(AppTerminal       APP_TERMINAL              "Enable Terminal app"                     DEFAULT ON)
config_option(AppTestOS         APP_TEST_OS               "Enable Test OS app"                      DEFAULT ON)
config_option(AppTetris         APP_TETRIS                "Enable Tetris app"                       DEFAULT ON)
config_option(AppSnake          APP_SNAKE                 "Enable Snake app"                        DEFAULT ON)
config_option(AppTestUser       APP_TEST_USER             "Enable Test User Space app"              DEFAULT OFF)
config_option(AppNetHack        APP_NETHACK               "Enable NetHack app"                      DEFAULT OFF)

#
# seL4 RefOS Build Options
#
config_option(RefosDebug         REFOS_DEBUG               "Enable Debug build of RefOS"            DEFAULT ON)
config_option(RefosDbgVerbose    REFOS_DEBUG_VERBOSE       "Enable Debug build of RefOS"            DEFAULT OFF)
config_string(RefosInitTask      REFOS_INIT_TASK           "Set the initial RefOS task"             DEFAULT "/fileserv/terminal")
config_string(RefosInitTaskPrio  REFOS_INIT_TASK_PRIO      "Set priority of initial RefOS task"     DEFAULT 50      UNQUOTE)
config_option(RefosAnsiColor     REFOS_ANSI_COLOUR_OUTPUT  "Enable ANSI color output"               DEFAULT ON)
config_string(RefosTimeZone      REFOS_TIMEZONE            "Set the RefOS time zone"                DEFAULT "AEST-10")
config_option(RefosStdioSerial   REFOS_STDIO_DSPACE_SERIAL "Enable StdIO Serial Port"               DEFAULT ON)
# CONFIG_REFOS_RUN_TESTS is not set
# CONFIG_REFOS_ENABLE_EGA is not set
# CONFIG_REFOS_HALT_ON_ERRNO is not set
# CONFIG_REFOS_ENABLE_KEYBOARD is not set

add_config_library(refos "${configure_string}")

# Set our custom domain schedule
RequireFile(SEL4TEST_DOMAIN_SCHEDULE domain_schedule.c CMAKE_FIND_ROOT_PATH_BOTH)
set(KernelDomainSchedule "${SEL4TEST_DOMAIN_SCHEDULE}" CACHE INTERNAL "")

if(KernelSel4ArchX86_64)
    SetSimulationScriptProperty(MEM_SIZE "3G")
endif()

GenerateSimulateScript()

# Declare a cache variable that enables/disablings the forcing of cache variables to
# the specific test values. By default it is disabled
set(Sel4testAllowSettingsOverride OFF CACHE BOOL "Allow user to override configuration settings")

# Define our top level settings. Whilst they have doc strings for readability here
# they are hiddein the cmake-gui as they cannot be reliably changed after the initial
# configuration, but enterprising users can still change them if they know what they
# are doing through advanced mode
# Users should initialize a build directory by doing something like
# mkdir build_sabre
# cd build_sabre
# ../init-build.sh -DARM=TRUE -DPLATFORM=sabre -DSIMULATION=TRUE
set(SIMULATION OFF CACHE BOOL "Include only simulation compatible tests")
set(RELEASE OFF CACHE BOOL "Performance optimized build")
set(VERIFICATION OFF CACHE BOOL "Only verification friendly kernel features")
set(BAMBOO OFF CACHE BOOL "Enable machine parseable output")
set(DOMAINS OFF CACHE BOOL "Test multiple domains")
set(SMP OFF CACHE BOOL "(if supported) Test SMP kernel")
set(PLATFORM "ia32" CACHE STRING "Platform to test")
set_property(CACHE PLATFORM PROPERTY STRINGS ${KernelX86Sel4Arch_all_strings} ${KernelARMPlatform_all_strings} ${KernelRiscVPlatform_all_strings})
set(ARM_HYP OFF CACHE BOOL "Hyp mode for ARM platforms")

# We use 'FORCE' when settings these values instead of 'INTERNAL' so that they still appear
# in the cmake-gui to prevent excessively confusing users
if (NOT Sel4testAllowSettingsOverride)
    # Determine the platform/architecture
    if (${PLATFORM} IN_LIST KernelX86Sel4Arch_all_strings)
        set(KernelArch x86 CACHE STRING "" FORCE)
        set(KernelX86Sel4Arch ${PLATFORM} CACHE STRING "" FORCE)
    elseif(${PLATFORM} IN_LIST KernelRiscVPlatform_all_strings)
        set(KernelArch riscv CACHE STRING "" FORCE)
        set(KernelRiscVPlatform ${PLATFORM} CACHE STRING "" FORCE)
        if(RISCV64)
            set(KernelRiscVSel4Arch "riscv64" CACHE STRING "" FORCE)
        else()
            set(KernelRiscVSel4Arch "riscv32" CACHE STRING "" FORCE)
        endif()
    else()
        if (NOT ${PLATFORM} IN_LIST KernelARMPlatform_all_strings)
            message(FATAL_ERROR "Unknown PLATFORM. Initial configuration may not work")
        endif()
        set(KernelArch arm CACHE STRING "" FORCE)
        set(KernelARMPlatform ${PLATFORM} CACHE STRING "" FORCE)

        if(ARM_HYP)
            set(KernelArmHypervisorSupport ON CACHE BOOL "" FORCE)
        endif()

        if(AARCH64)
            set(KernelArmSel4Arch "aarch64" CACHE STRING "" FORCE)
        elseif(AARCH32)
            set(KernelArmSel4Arch "aarch32" CACHE STRING "" FORCE)
            if(ARM_HYP)
                set(KernelArmSel4Arch "arm_hyp" CACHE STRING "" FORCE)
            endif()
        endif()

        # Elfloader settings that correspond to how Data61 sets its boards up.
        ApplyData61ElfLoaderSettings(${KernelARMPlatform} ${KernelArmSel4Arch})
    endif()

    if(SIMULATION)
        ApplyCommonSimulationSettings(${KernelArch})
    else()
        if(KernelArchX86)
            set(KernelIOMMU ON CACHE BOOL "" FORCE)
        endif()
    endif()


    # sel4test specific config settings.

    # sel4test creates processes from libsel4utils that require relatively large cspaces
    set(LibSel4UtilsCSpaceSizeBits 17 CACHE STRING "" FORCE)

    if (SIMULATION)
        set(Sel4testHaveCache OFF CACHE BOOL "" FORCE)
    else()
        set(Sel4testHaveCache ON CACHE BOOL "" FORCE)
    endif()
    if (KernelArchRiscV OR (SIMULATION AND KernelArchARM))
        set(Sel4testHaveTimer OFF CACHE BOOL "" FORCE)
    else()
        set(Sel4testHaveTimer ON CACHE BOOL "" FORCE)
    endif()

    # Check the hardware debug API non simulated (except for ia32, which can be simulated),
    # skipping any aarch64 platform, as this does not yet support the debug API, and a
    # few other miscelaneous platforms that do not support it
    if (((NOT SIMULATION) OR KernelSel4ArchIA32) AND (NOT KernelSel4ArchAarch64)
            AND (NOT KernelArchRiscV)
            AND (NOT ("${KernelARMPlatform}" STREQUAL "exynos5250"))
            AND (NOT ("${KernelARMPlatform}" STREQUAL "am335x"))
            AND (NOT ("${KernelARMPlatform}" STREQUAL "omap3"))
            AND (NOT ("${KernelARMPlatform}" STREQUAL "kzm"))
            AND (NOT ("${KernelARMPlatform}" STREQUAL "exynos5410"))
            )
        set(HardwareDebugAPI ON CACHE BOOL "" FORCE)
    else()
        set(HardwareDebugAPI OFF CACHE BOOL "" FORCE)
    endif()

    ApplyCommonReleaseVerificationSettings(${RELEASE} ${VERIFICATION})

    # Need to disable GC sections as it causes our tests to be stripped sometimes
    set(UserLinkerGCSections OFF CACHE BOOL "" FORCE)

    if (BAMBOO)
        set(LibSel4TestPrintXML ON CACHE BOOL "" FORCE)
        set(LibSel4BufferOutput ON CACHE BOOL "" FORCE)
        set(KernelIRQReporting OFF CACHE BOOL "" FORCE)
    else()
        set(LibSel4TestPrintXML OFF CACHE BOOL "" FORCE)
        set(LibSel4BufferOutput OFF CACHE BOOL "" FORCE)
        set(KernelIRQReporting ON CACHE BOOL "" FORCE)
    endif()

    if (DOMAINS)
        set(KernelNumDomains 16 CACHE STRING "" FORCE)
    else()
        set(KernelNumDomains 1 CACHE STRING "" FORCE)
    endif()

    if (SMP)
        set(KernelMaxNumNodes 4 CACHE STRING "" FORCE)
    else()
        set(KernelMaxNumNodes 1 CACHE STRING "" FORCE)
    endif()
endif()
