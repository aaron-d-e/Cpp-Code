cmake_minimum_required(VERSION 3.30)
project(Project4CLion)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project4CLion main.cpp
        proj4-itemInfo.cpp
        proj4-itemInfo.h
        proj4-testmain.cpp)
