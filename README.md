# Toy Modular Project

A modern C++20 modular shared library supporting both traditional headers and C++20 modules. 

## Structure

```
include/      # Public headers (demo.hpp is the user entry point)
lib/          # Traditional source
modules/      # All .ixx module units (auto-generated)
scripts/      # Python scripts for module conversion
app/          # Example app
CMakeLists.txt
```

## Building

> **Note:** The example build commands below use `-DCMAKE_TOOLCHAIN_FILE=../llvm.toolchain.cmake` to ensure the use of a custom LLVM Clang installation. You should adjust the command to use your own compilers that provide C++20 modules support.

**Traditional:**
```bash
cmake -G Ninja .. -DCMAKE_TOOLCHAIN_FILE=../llvm.toolchain.cmake
ninja
```

**Modules:**
```bash
cmake -G Ninja .. -DCMAKE_TOOLCHAIN_FILE=../llvm.toolchain.cmake -DDEMO_USE_MODULES=ON
ninja
```

## Regenerate Modules

```bash 
python scripts/convert_header_to_module.py include/non_template.hpp modules/non_template.ixx
python scripts/convert_header_to_module.py include/template.hpp modules/template.ixx
python scripts/convert_source_to_module.py lib/lib.cpp modules/lib.ixx
python scripts/generate_primary_module.py modules/demo.ixx modules/non_template.ixx modules/template.ixx
```

---
- All module files are auto-documented with their origin and conversion script.