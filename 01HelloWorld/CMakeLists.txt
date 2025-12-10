cmake_minimum_required(VERSION 3.16)

project(HelloWorld CXX)

# Print selected compilers so users can verify what CMake chose
message(STATUS "C compiler: ${CMAKE_C_COMPILER}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER} (${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION})")

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source directory
add_subdirectory(src)

# Optionally set an install target
#install(TARGETS hello_world RUNTIME DESTINATION bin)
