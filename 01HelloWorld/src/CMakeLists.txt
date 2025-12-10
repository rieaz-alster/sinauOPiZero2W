set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_BUILD_TYPE Debug)

add_executable(hello_world main.cpp)

set_target_properties(hello_world PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "../"
)


target_include_directories(hello_world PRIVATE ${CMAKE_SOURCE_DIR}/include)
