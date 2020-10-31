cmake_minimum_required(VERSION 3.10)
project(paul VERSION 0.1.0)

set(CMAKE_VERBOSE_MAKEFILE FALSE)
set(CMAKE_C_STANDARD 90)

add_subdirectory(src bin)
