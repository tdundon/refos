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

project(file_server C)

set(configure_string "")

add_config_library(file_server "${configure_string}")

file(GLOB deps
    src/*.c src/tests/*.c src/arch/${KernelArch}/*.c src/plat/${KernelPlatform}/*.c
    src/arch/${KernelArch}/*.S src/plat/${KernelPlatform}/*.S
)

list(APPEND aList
       "/home/papa/develop/sel4/refos/build/projects/refos/apps/timer_server/timer_server"
       "/home/papa/develop/sel4/refos/build/projects/refos/apps/terminal/terminal"
       "/home/papa/develop/sel4/refos/build/projects/refos/apps/tetris/tetris"
       "/home/papa/develop/sel4/refos/build/projects/refos/apps/snake/snake"
       "/home/papa/develop/sel4/refos/projects/refos/apps/file_server/files/news"
       "/home/papa/develop/sel4/refos/projects/refos/apps/file_server/files/hh"
       "/home/papa/develop/sel4/refos/projects/refos/apps/file_server/files/license"
       "/home/papa/develop/sel4/refos/projects/refos/apps/file_server/files/hello.txt"
       "/home/papa/develop/sel4/refos/projects/refos/apps/file_server/files/nhdat"
       "/home/papa/develop/sel4/refos/projects/refos/apps/file_server/files/logfile"
       "/home/papa/develop/sel4/refos/projects/refos/apps/file_server/files/nethackrc"
)
#message("file_server: aList = " ${aList})

MakeCPIO(archive.o "${aList}")

add_executable(file_server EXCLUDE_FROM_ALL ${deps} archive.o)
target_link_libraries(file_server Configuration muslc sel4 elf refossys refos cpio datastruct)
target_compile_options(file_server PRIVATE -Werror -g -O2)

