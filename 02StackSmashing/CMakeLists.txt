cmake_minimum_required(VERSION 3.15)
project(stack_smash VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create executable
add_executable(stack_smash main.cpp)

# Compiler warnings and debug info
target_compile_options(stack_smash PRIVATE -Wall -Wextra -g)

# Put runtime binary into build/bin for a stable path
set_target_properties(stack_smash PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Optional sanitizers
option(ENABLE_SANITIZERS "Enable Address/Undefined sanitizers" OFF)
if(ENABLE_SANITIZERS)
  if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(stack_smash PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(stack_smash PRIVATE -fsanitize=address,undefined)
  endif()
endif()

install(TARGETS stack_smash RUNTIME DESTINATION bin)

message(STATUS "Configured project '${PROJECT_NAME}' (sanitizers=${ENABLE_SANITIZERS})")
