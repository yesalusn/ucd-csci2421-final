cmake_minimum_required(VERSION 3.5)
project(ucd_csci2421_final)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp AVLNode.cpp AVLNode.h Contact.cpp Contact.h
        AVLTree.cpp AVLTree.h ContactDatabase.cpp ContactDatabase.h)

add_executable(ucd_csci2421_final ${SOURCE_FILES})