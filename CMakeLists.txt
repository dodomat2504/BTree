cmake_minimum_required(VERSION 3.5)

project(BTree LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(BTree main.cpp dbtree.h dbinsearchtree.h)
