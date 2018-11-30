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

project(console_server C)

set(configure_string "")

add_config_library(console_server "${configure_string}")

file(GLOB deps
    src/*.c src/tests/*.c src/arch/${KernelArch}/*.c src/plat/${KernelPlatform}/*.c
    src/arch/${KernelArch}/*.S src/plat/${KernelPlatform}/*.S
)

add_executable(console_server EXCLUDE_FROM_ALL ${deps})
target_link_libraries(console_server Configuration muslc sel4 refossys refos datastruct platsupport vterm)
target_compile_options(console_server PRIVATE -Werror -g)
