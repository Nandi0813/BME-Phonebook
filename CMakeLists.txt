cmake_minimum_required(VERSION 3.24)
project(Project)

set(CMAKE_CXX_STANDARD 11)

add_definitions(-DMEMTRACE)

add_executable(Project
        main.cpp
        Libs/memtrace.cpp
        Libs/memtrace.h
        Libs/gtest_lite.h
        Managers/String.cpp
        Managers/String.h
        Managers/contact.h
        Managers/directory.cpp
        Managers/directory.h
        Managers/name.h
        Managers/address.h
        Managers/phone.h
        Managers/list.hpp)
