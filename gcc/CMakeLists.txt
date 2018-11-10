cmake_minimum_required(VERSION 3.5)

project(gcc)
set(src main.c ./function/mytool1.c ./function/mytool1.h ./function/mytool2.c ./function/mytool2.h)


add_executable(gcc.bin ${src}) 