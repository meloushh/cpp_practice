- Libraries:
    - std (vector, map, unordered_map, filesystem, string, wstring, format)
    - MFC
    - ImGUI
    - CMake
    - Boost
    - raylib
    - Unreal Engine
- Compilers
    - gcc (mingw–w64)
    - msvc
    - clang (mingw-llvm)
- Build systems
    - cmake
    - premake
    - make
    - scons

# VS project setup
Make sure to apply these to all platforms and configurations.

- Project settings -> general: 
    - Output directory
    - Intermediate directory
    - Language level (17 recommended)
- Project settings -> C/C++:
    - Additional include directories
- Project settings -> Linker:
    - Additional dependencies - OS dependencies etc.
