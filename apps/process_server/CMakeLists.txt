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

project(process_server C)

set(configure_string "")

add_config_library(process_server "${configure_string}")

file(GLOB deps
    src/*.c src/test/*.c
    src/dispatchers/*.c
    src/system/addrspace/*.c
    src/system/memserv/*.c
    src/system/process/*.c
)

list(APPEND aList
        "/home/papa/develop/sel4/refos/build/projects/refos/apps/file_server/file_server"
        "/home/papa/develop/sel4/refos/build/projects/refos/apps/test_os/test_os"
        "/home/papa/develop/sel4/refos/build/projects/refos/apps/selfloader/selfloader"
        "/home/papa/develop/sel4/refos/build/projects/refos/apps/console_server/console_server"
)

MakeCPIO(archive.o "${aList}")

add_executable(process_server EXCLUDE_FROM_ALL ${deps} archive.o)
target_include_directories(process_server PRIVATE include)
target_link_libraries(process_server Configuration
    muslc sel4 sel4muslcsys sel4allocman sel4platsupport
    sel4vka elf cpio refos sel4utils datastruct sel4debug
    sel4simple utils platsupport sel4vspace
    sel4simple-default)
target_compile_options(process_server PRIVATE -Werror -g -std=gnu99 -O2)

# Set this image as the rootserver
DeclareRootserver(process_server)
