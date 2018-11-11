cmake_minimum_required(VERSION 3.5)

project(gcc)
set(src main.cpp)
aux_source_directory(./function src)


add_executable(gcc.bin ${src}) 