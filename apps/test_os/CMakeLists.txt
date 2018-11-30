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

project(test_os C)

set(configure_string "")

add_config_library(test_os "${configure_string}")

file(GLOB deps
    src/*.c src/tests/*.c src/arch/${KernelArch}/*.c src/plat/${KernelPlatform}/*.c
    src/arch/${KernelArch}/*.S src/plat/${KernelPlatform}/*.S
)

add_executable(test_os EXCLUDE_FROM_ALL ${deps})
target_link_libraries(test_os Configuration muslc sel4 refossys refos datastruct)
target_compile_options(test_os PRIVATE -Werror -g -O2)
