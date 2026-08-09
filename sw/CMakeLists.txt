cmake_minimum_required(VERSION 3.12)
project(AperiodicQuasicrystalEngine CXX)

# Set C++ standard to C++17 for lambda expressions and modern features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optimization flags for high-performance mesh generation
if(MSVC)
    add_compile_options(/O2)
else()
    add_compile_options(-O3 -Wall -Wextra)
endif()

# Define the executable target using the correct testbench file name
add_executable(quasicrystal_app
    3D_aperiodic_testbench.cpp
    3D_aperiodic_quasicrystal_engine.hpp
)

# Include current directory for seamless header resolution
target_include_directories(quasicrystal_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)