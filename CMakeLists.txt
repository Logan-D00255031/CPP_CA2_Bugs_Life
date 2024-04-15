cmake_minimum_required(VERSION 3.28)
project(CA2)

set(CMAKE_CXX_STANDARD 17)

add_executable(CA2 main.cpp
        Bug.h
        Crawler.cpp
        Crawler.h
        Bug.cpp
        Hopper.cpp
        Hopper.h)
