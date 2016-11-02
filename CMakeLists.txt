cmake_minimum_required(VERSION 3.5)
project(ucd_csci2421_final)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Node.h BSTree.h BSTree.cpp Contact.h Contact.cpp MainMenu.cpp MainMenu.h)

add_executable(ucd_csci2421_final ${SOURCE_FILES})