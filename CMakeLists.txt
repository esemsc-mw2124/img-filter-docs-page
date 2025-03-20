cmake_minimum_required(VERSION 3.21)

# Conditional compiler setting
if(APPLE)
    find_program(GCC NAMES gcc-14 gcc-13 gcc-12 gcc-11)
    find_program(GXX NAMES g++-14 g++-13 g++-12 g++-11)
    if(GCC AND GXX)
        set(CMAKE_C_COMPILER ${GCC})
        set(CMAKE_CXX_COMPILER ${GXX})
    else()
        message(FATAL_ERROR "No suitable gcc/g++ compiler found. Please install gcc and g++.")
    endif()
elseif(UNIX)
    set(CMAKE_C_COMPILER gcc)
    set(CMAKE_CXX_COMPILER g++)
endif()

# Project name and version
project(APImageFilters VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/tests)

# Gather all source files automatically
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/src/*.h)
file(GLOB_RECURSE TEST_FILES ${CMAKE_SOURCE_DIR}/tests/*.cpp)

set_source_files_properties(src/Filter-old.cpp PROPERTIES EXCLUDE_FROM_ALL TRUE)

# Define main executable
add_executable(APImageFilters ${SRC_FILES} ${HEADER_FILES})

# Define tests executable
list(FILTER SRC_FILES EXCLUDE REGEX ".*main\\.cpp$")
add_executable(TestBlur ${CMAKE_SOURCE_DIR}/tests/2D/TestBlur.cpp ${SRC_FILES})
add_executable(TestSimpleFilter ${CMAKE_SOURCE_DIR}/tests/2D/TestSimpleFilter.cpp ${SRC_FILES})
add_executable(TestEdgeDetector ${CMAKE_SOURCE_DIR}/tests/2D/TestEdgeDetector.cpp ${SRC_FILES})
add_executable(TestSharpener ${CMAKE_SOURCE_DIR}/tests/2D/TestSharpener.cpp ${SRC_FILES})
add_executable(TestProjection ${CMAKE_SOURCE_DIR}/tests/3D/TestProjection.cpp ${SRC_FILES})
add_executable(TestVolume ${CMAKE_SOURCE_DIR}/tests/3D/TestVolume.cpp ${SRC_FILES})
add_executable(TestBlurFilter3D ${CMAKE_SOURCE_DIR}/tests/3D/TestBlurFilter3D.cpp ${SRC_FILES})
# add_executable(TestSlice ${CMAKE_SOURCE_DIR}/tests/3D/TestSlice.cpp ${SRC_FILES})


# Enable testing
include(CTest)
enable_testing()

# Include the tests
include(${CMAKE_SOURCE_DIR}/cmdtests.cmake)

message(STATUS "CMake configuration complete. Run 'make' to build the project.")

