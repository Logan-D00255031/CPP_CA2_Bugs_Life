cmake_minimum_required(VERSION 3.25)
project(CA2)

set(CMAKE_CXX_STANDARD 17)

add_executable(CA2 main.cpp
        Bug.h
        Bug.cpp
        Crawler.h
        Crawler.cpp
        Hopper.h
        Hopper.cpp
        )
