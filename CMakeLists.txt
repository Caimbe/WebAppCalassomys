project(WebAppCalassomys)
cmake_minimum_required(VERSION 2.8)
include_directories(. include)
aux_source_directory(src SRC)
aux_source_directory(include INCLUDE)
list(APPEND FULL_SRC
    ${SRC}
    ${INCLUDE} )
add_library(${PROJECT_NAME} STATIC ${FULL_SRC} )
target_link_libraries(${PROJECT_NAME} cppcms booster htmlcxx )

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fPIC -std=c++11")
endif()
