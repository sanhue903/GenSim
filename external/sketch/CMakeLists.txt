add_library(sketch INTERFACE)

target_include_directories(sketch INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/blaze>
    $<INSTALL_INTERFACE:include>
)


target_compile_options(sketch INTERFACE
    $<$<CXX_COMPILER_ID:GNU>:-msse4.1 -mpopcnt>
    $<$<CXX_COMPILER_ID:Clang>:-msse4.1 -mpopcnt>
)