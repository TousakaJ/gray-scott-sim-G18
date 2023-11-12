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
find_package(Boost REQUIRED)

# If Boost library is found, include its directories
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

# Specify source files
set(SOURCES gs.cpp checks.cpp)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Link Boost library to the target
if(Boost_FOUND)
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()