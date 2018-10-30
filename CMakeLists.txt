cmake_minimum_required(VERSION 3.12)
project(UtPod)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(UtPod
        song.cpp
        song.h
        UtPod.cpp
        UtPod.h
        UtPod_Driver.cpp)
