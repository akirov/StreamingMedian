cmake_minimum_required(VERSION 3.1)

project(StreamingMedian)


set (CMAKE_CXX_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

set(INSTALL_DIR ${CMAKE_SOURCE_DIR}/bin)


add_subdirectory(src)
add_subdirectory(tests)


enable_testing()

add_test(NAME    median_test 
         COMMAND median_test)
