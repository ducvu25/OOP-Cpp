cmake_minimum_required(VERSION 3.10)
project(adt_list_assignment)

set(CMAKE_CXX_STANDARD 14)

add_executable(list
        list.cpp list.h
        dlinkedlist.cpp dlinkedlist.h
        vsarray.h vsarray.cpp
        object.h object.cpp
        person.h person.cpp
        integer.cpp integer.h
        test.cpp
        sorted_double_linked_list.cpp
        sorted_double_linked_list.h
        comparable.cpp
        comparable.h)