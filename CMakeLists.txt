cmake_minimum_required(VERSION 3.16)
project(GenSim VERSION 0.1.0 LANGUAGES CXX)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(external/sketch)
add_subdirectory(gensim)

add_executable(demo demo/demo.cpp)
target_link_libraries(demo PRIVATE gensim)


include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.8.1 # o la última versión estable
)

FetchContent_MakeAvailable(Catch2)


enable_testing()

add_executable(test_gensim tests/test_base.cpp)
target_link_libraries(test_gensim PRIVATE gensim Catch2::Catch2WithMain)
include(CTest)
include(Catch)
catch_discover_tests(test_gensim)

