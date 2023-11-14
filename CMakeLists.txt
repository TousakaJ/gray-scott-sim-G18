# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# Project's name
project(gs)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

# Add compile warning flags
add_compile_options(-Wall)

# Find Boost library
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# If Boost library is found, include its directories
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

# Specify source files for the main executable
set(SOURCES gs.cpp checks.cpp)
add_executable(gs ${SOURCES})

# Specify source files for checks
set(CHECKS_SOURCES checks.cpp)

# Specify source files for the test executable
set(TEST_SOURCES tests.cpp ${CHECKS_SOURCES})

# Add test executable target
add_executable(gs_test tests.cpp checks.cpp gs.cpp)

# Link Boost library to the test executable
if(Boost_FOUND)
    target_link_libraries(gs_test ${Boost_LIBRARIES} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
endif()
target_compile_definitions(gs_test PRIVATE UNIT_TEST)

# Add a test
add_test(NAME gs_test COMMAND gs_test)

# Define the UNIT_TEST macro for excluding main in gs.cpp
target_compile_definitions(gs_test PRIVATE UNIT_TEST)
