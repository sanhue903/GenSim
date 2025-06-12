add_library(gensim STATIC ./gensim.cpp)
target_include_directories(gensim PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(gensim PUBLIC sketch)