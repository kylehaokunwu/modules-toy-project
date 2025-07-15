# Modular Toy Project (C++20 Modules & Traditional Headers)

This project demonstrates an **experimental dual-mode C++ library** that supports both:
- **Traditional header-based builds** (classic C++ with headers and source files)
- **C++20 module-based builds** (using Clang and CMake)

## Key Features
- **Single user-facing header (`demo.hpp`)**: Works for both modes
- **Template headers**: Use preprocessor logic to act as both a header and a module interface unit
- **Non-template functions**: Declared in module interface units and implemented in a traditional source file
- **Switch build modes with a single CMake option**

## Project Structure
```
include/           # Public headers (template and non-template)
lib/               # Traditional implementation (lib.cpp)
modules/           # Module interface units (.ixx wrappers)
app/               # Example application
CMakeLists.txt     # Root build configuration
```

## Building the Project

### Prerequisites
- CMake 3.28+
- Clang 16+ (with C++20 modules support)
- Ninja (recommended)


### Traditional Header-Based Build (Default)
```sh
mkdir -p build && cd build
cmake -G Ninja ..
ninja
./app/demo_app
```

### C++20 Module-Based Build
```sh
mkdir -p build && cd build
cmake -G Ninja .. -DDEMO_USE_MODULES=ON
ninja
./app/demo_app
```

## Demonstration

### Header-Based Build with Debug Mode OFF
```sh
# NOTE: The -DCMAKE_TOOLCHAIN_FILE=../llvm.toolchain.cmake flag is used here
# to enable LLVM Clang toolchain and macOS SDK on my machine only. 

mkdir build && cd build
cmake -G Ninja .. -DCMAKE_TOOLCHAIN_FILE=../llvm.toolchain.cmake
ninja
./app/demo_app
```

**Output:**
```
Magic number: 42
100 + magic = 142
```

### Module-Based Build with Debug Mode ON
```sh
# NOTE: The -DCMAKE_TOOLCHAIN_FILE=../llvm.toolchain.cmake flag is used here
# to enable LLVM Clang toolchain and macOS SDK on my machine only. 

mkdir build && cd build
cmake -G Ninja .. -DCMAKE_TOOLCHAIN_FILE=../llvm.toolchain.cmake -DDEMO_USE_MODULES=ON -DDEMO_DEBUG=ON
ninja
./app/demo_app
```

**Output:**
```
Getting magic number...
Magic number: 42
Getting magic number...
100 + magic = 142
```