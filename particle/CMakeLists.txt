cmake_minimum_required(VERSION 3.0)
project(particule LANGUAGES CXX)

file ( GLOB HEADERS *.h *.hpp)

file ( GLOB SOURCES *.cpp)

add_library(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/../vectorMatrix
	${CMAKE_CURRENT_SOURCE_DIR}/../image)

target_link_libraries(${PROJECT_NAME} vector_matrix image)
