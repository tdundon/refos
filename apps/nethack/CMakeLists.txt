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

project(nethack C)

set(configure_string "")

add_config_library(nethack "${configure_string}")

file(GLOB deps
    src/*.c src/tests/*.c src/arch/${KernelArch}/*.c src/plat/${KernelPlatform}/*.c
    src/arch/${KernelArch}/*.S src/plat/${KernelPlatform}/*.S
)

add_executable(nethack EXCLUDE_FROM_ALL ${deps})
target_include_directories(nethack PRIVATE src/nethack-3.4.3/include)
target_link_libraries(nethack Configuration muslc sel4 refossys refos datastruct)
target_compile_options(nethack PRIVATE -Werror -g -D_BSD_SOURCE -O2 -DTTY_GRAPHICS -DANSI_DEFAULT -DDLB -DNO_FILE_LINKS- -DDLBLIB -w)
