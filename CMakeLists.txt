cmake_minimum_required(VERSION 3.24)
project(Project)

set(CMAKE_CXX_STANDARD 11)

add_definitions(-DMEMTRACE)

add_executable(Project
        main.cpp
        memtrace.cpp
        memtrace.h
        gtest_lite.h
        String.cpp
        String.h
        contact.h
        directory.cpp
        directory.h
        name.h
        address.h
        phone.h
        list.hpp)
