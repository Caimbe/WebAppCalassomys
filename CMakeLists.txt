project(WebAppCalassomys)
cmake_minimum_required(VERSION 2.8)
include_directories(. include)
aux_source_directory(src SRC_LIST)
add_library(${PROJECT_NAME} STATIC ${SRC_LIST})


if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++11")
endif()
