# C++ Hello World (CMake)

This is a tiny sample project that demonstrates how to initialize and use CMake
for a simple C++ application.

Build & run (Unix):
```bash
mkdir -p build
cd build
cmake ..
cmake --build .
./hello_world
```

Or use the default Make generator directly:
```bash
cmake -S . -B build
cmake --build build --config Release
```

Force using GCC / g++
--------------------

If you want to force CMake to use GCC (instead of Clang, MSVC, etc.), here are several safe options:

- Using environment variables (recommended if you just want a one-off):
```bash
mkdir -p build && cd build
CC=gcc CXX=g++ cmake ..
cmake --build .
```
- Passing compilers directly to CMake (configure step):
```bash
mkdir -p build && cd build
cmake -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ ..
cmake --build .
```
- Use the provided toolchain file (recommended if you re-use it across machines):
```bash
mkdir -p build && cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchain-gcc.cmake ..
cmake --build .
```

VS Code (with CMake Tools extension)
-----------------------------------

Open the project in VS Code. In the CMake Tools status bar at the bottom, choose a Kit that specifies GCC ("GCC x.x.x") or add `cmake.configureArgs` in `.vscode/settings.json` like: 

```json
{
	"cmake.configureArgs": ["-DCMAKE_C_COMPILER=/usr/bin/gcc", "-DCMAKE_CXX_COMPILER=/usr/bin/g++"]
}
```

Note: Changing compilers should be done at configure time. If CMake already configured the project with a different compiler, delete the `build/` directory and re-run `cmake` with the new options.
