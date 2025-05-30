cmake_minimum_required(VERSION 3.14)
project(GenSim VERSION 0.1.0 LANGUAGES CXX)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Incluir directorios de encabezados
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Crear la biblioteca GenSim
add_library(gensim STATIC
    src/gensim.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# Crear el ejecutable demo
add_executable(gensim_demo demo/demo.cpp)
target_link_libraries(gensim_demo PRIVATE gensim)
