cmake_minimum_required(VERSION 3.1)


include_directories (${CMAKE_CURRENT_SOURCE_DIR})

add_library (median STATIC MedianSet.cpp)
#add_library (median SHARED MedianSet.cpp)

add_executable (demo main.cpp)
#target_link_libraries (demo -static)
target_link_libraries (demo median)

install (TARGETS median demo DESTINATION ${INSTALL_DIR})


# Additional clean step : clean installed files
set_property(DIRECTORY PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    "${INSTALL_DIR}/demo"
    "${INSTALL_DIR}/demo.exe"
    "${INSTALL_DIR}/libmedian.a"
    "${INSTALL_DIR}/libmedian.so"
    "${INSTALL_DIR}/libmedian.dll"
    "${INSTALL_DIR}/libmedian.dll.a"
)
