# Toolchain file that selects system GCC/g++ compilers.
# Use with: cmake -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain-gcc.cmake ..

# Path to gcc/g++. If you have them elsewhere, override via command line or edit the file.
set(CMAKE_C_COMPILER "/usr/bin/gcc" CACHE PATH "C compiler")
set(CMAKE_CXX_COMPILER "/usr/bin/g++" CACHE PATH "C++ compiler")

# Verify compilers exist and print some info
if(NOT EXISTS ${CMAKE_C_COMPILER})
  message(WARNING "C compiler not found at ${CMAKE_C_COMPILER}. Please install GCC or update this toolchain file.")
endif()
if(NOT EXISTS ${CMAKE_CXX_COMPILER})
  message(WARNING "C++ compiler not found at ${CMAKE_CXX_COMPILER}. Please install g++ or update this toolchain file.")
endif()
message(STATUS "GCC toolchain file: using ${CMAKE_C_COMPILER} and ${CMAKE_CXX_COMPILER}")
