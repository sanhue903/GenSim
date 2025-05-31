add_library(gensim STATIC ./gensim.cpp)
target_include_directories(gensim PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR/include}
)



