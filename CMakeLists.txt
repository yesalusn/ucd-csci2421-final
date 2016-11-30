cmake_minimum_required(VERSION 3.5)
project(ucd_csci2421_final)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Node.h BSTree.h BSTree.cpp Contact.h Contact.cpp Menu.cpp Menu.h
        AppFunctions.cpp AppFunctions.h SearchFunctions.cpp SearchFunctions.h Printing.cpp Printing.h
        AddContact.cpp AddContact.h EditContact.cpp EditContact.h DeleteContact.cpp DeleteContact.h)

add_executable(ucd_csci2421_final ${SOURCE_FILES})