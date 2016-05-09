cmake_minimum_required(VERSION 3.5)
project(42sh_builtin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES sources/environment/env_builder.c
        sources/environment)
add_executable(42sh_builtin ${SOURCE_FILES})