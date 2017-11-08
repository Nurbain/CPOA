cmake_minimum_required(VERSION 3.0)

project(vector_matrix LANGUAGES CXX)

find_package( Threads REQUIRED )

set(GT ${CMAKE_CURRENT_SOURCE_DIR}/../GT)
link_directories(${GT}/lib)





file ( GLOB HEADERS *.h *.hpp)

file ( GLOB SOURCES *.cpp)

add_library(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${GT}/include)


add_subdirectory(tests)

target_link_libraries(${PROJECT_NAME}
        debug gtestd optimized gtest
        debug gmockd optimized gmock
        ${CMAKE_THREAD_LIBS_INIT})
