cmake_minimum_required(VERSION 3.5)

project(simhash)

add_library(simhash SHARED 
    src/simhash.cpp
)

target_include_directories(simhash
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

install(TARGETS simhash
    LIBRARY DESTINATION lib)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ 
    DESTINATION include)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/deps/
    DESTINATION etc)
