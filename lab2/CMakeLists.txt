cmake_minimum_required(VERSION 4.2)


set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")


set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(MyLab1 CXX)


add_executable(main)


target_compile_options(main PRIVATE /utf-8)

set_property(TARGET main PROPERTY CXX_MODULE_STD ON)

target_sources(main

    PUBLIC

    FILE_SET CXX_MODULES FILES

        source/funcs.cppm

    PRIVATE

        source/main.cpp

)