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

project(timer_server C)

set(configure_string "")

config_option(Sel4testHaveTimer HAVE_TIMER
    "Enable tests that require a timer driver"
    DEFAULT ON
)

config_option(Sel4testHaveCache HAVE_CACHE
    "Enable tests that require a functioning cache"
    DEFAULT ON
)

add_config_library(timer_server "${configure_string}")

file(GLOB deps
    src/*.c src/tests/*.c src/arch/${KernelArch}/*.c src/plat/${KernelPlatform}/*.c
    src/arch/${KernelArch}/*.S src/plat/${KernelPlatform}/*.S
)

add_executable(timer_server EXCLUDE_FROM_ALL ${deps})
target_link_libraries(timer_server Configuration muslc sel4 refossys refos datastruct platsupport utils)
target_compile_options(timer_server PRIVATE -Werror -g -O2)
