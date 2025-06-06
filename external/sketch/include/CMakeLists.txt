add_subdirectory(aesctr)
add_subdirectory(blaze)
add_subdirectory(circularqueue)
add_subdirectory(compactvector)
add_subdirectory(flathashmap)
add_subdirectory(libpopcnt)
add_subdirectory(vec)
add_subdirectory(xxhash)

add_library(sketch)
target_include_directories(sketch INTEFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/sketch)
    