cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_COMPILER C:/Program Files/Microsoft Visual Studio/2022/Professional/VC/Tools/MSVC/14.33.31629/bin/Hostx64/x64/cl.exe)
set(CMAKE_INSTALL_PREFIX C:/Users/adria/Desktop/Codes/FilesCpp-2/${PROJECT_NAME})

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/src/vcpkg/installed/x64-windows/share/sfml)
find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)
include_directories(C:/src/vcpkg/packages/sfml_x64-windows/include)

add_executable(untitled main.cpp)

target_link_libraries(untitled sfml-system sfml-network sfml-graphics sfml-window)