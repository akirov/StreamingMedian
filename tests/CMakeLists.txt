cmake_minimum_required(VERSION 3.1)


include(ExternalProject)

set (GTEST_ROOT ${CMAKE_SOURCE_DIR}/tests/googletest-release-1.7.0)

ExternalProject_Add(
    gtest
    DOWNLOAD_COMMAND ""
    PREFIX ${GTEST_ROOT}
    SOURCE_DIR ${GTEST_ROOT}
    BINARY_DIR ${GTEST_ROOT}/build
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(gtest source_dir binary_dir)

add_executable(median_test median_test.cpp)

add_dependencies(median_test median gtest)

include_directories(${source_dir}/include
                    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(median_test median 
                                  ${binary_dir}/libgtest.a
                                  ${binary_dir}/libgtest_main.a
)

if(UNIX)  # AND NOT CYGWIN
    target_link_libraries(median_test pthread)
endif(UNIX)  # AND NOT CYGWIN


install (TARGETS median_test DESTINATION ${INSTALL_DIR})


# Clean installed test exe and geneated googletest files
set_property(DIRECTORY PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    "${INSTALL_DIR}/median_test"
    "${INSTALL_DIR}/median_test.exe"
    "${GTEST_ROOT}/build"
    "${GTEST_ROOT}/tmp"
    "${GTEST_ROOT}/src/gtest-stamp"
)
