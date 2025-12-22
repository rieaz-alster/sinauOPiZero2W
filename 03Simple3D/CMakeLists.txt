cmake_minimum_required(VERSION 3.10)
project(Simple3D)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(simple3d main.cpp)

# Optional: Add include directories
target_include_directories(simple3d PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib/glm-1.0.2)

# Optional: Link libraries
target_link_libraries(simple3d PRIVATE GLESv2 EGL glfw)