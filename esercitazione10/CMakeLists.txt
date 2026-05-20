cmake_minimum_required(VERSION 3.20)
project(gradiente_coniugato) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

include_directories(/usr/include/eigen3)

set(SOURCES test_gradiente.cpp)
add_executable(gradiente_coniugato ${SOURCES})