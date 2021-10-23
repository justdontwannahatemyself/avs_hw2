cmake_minimum_required(VERSION 3.20)
project(avs_dz2)

set(CMAKE_CXX_STANDARD 14)

add_executable(avs_dz2 main.cpp animal.h animal.cpp fish.h fish.cpp bird.cpp bird.h beast.h beast.cpp rnd.h container.h container.cpp)
