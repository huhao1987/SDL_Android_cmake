cmake_minimum_required(VERSION 3.18.1)

project("main")

add_subdirectory(SDL)
INCLUDE_DIRECTORIES("SDL/include")

add_library(
        main
        SHARED
        sample.cpp)
target_link_libraries(
        main
        SDL2)
