cmake_minimum_required(VERSION 3.16)
project(GenSim VERSION 0.1.0 LANGUAGES CXX)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(external/sketch/include)
add_subdirectory(gensim)

add_executable(demo demo/demo.cpp)
target_link_libraries(demo PRIVATE gensim)
