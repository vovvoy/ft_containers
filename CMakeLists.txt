cmake_minimum_required(VERSION 3.17)
project(container)

set(CMAKE_CXX_STANDARD 98)

add_executable(container main.cpp
        List/List.hpp
        List/ListNode.hpp
        Tools/Extra.hpp
        Tools/MapBase.hpp
        Tools/MapNode.hpp
        Tools/Pair.hpp
        Tools/Traits.hpp
        Stack/Stack.hpp
        Vector/Vector.hpp
        Queue/Queue.hpp
        Map/Map.hpp
        Iterators/ListIterator.hpp
        Iterators/MapIterator.hpp
        Iterators/RandomAccessIterator.hpp
        Iterators/ReverseIterator.hpp)