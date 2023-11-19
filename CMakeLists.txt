cmake_minimum_required(VERSION 3.24)
project(8___training_Mnist CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(8___training_Mnist main.cpp
        Data.h "DataHandler.h" Data.cpp DataHandler.cpp)
