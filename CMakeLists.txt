cmake_minimum_required(VERSION 3.13)
project(EnigmaM3)

set(CMAKE_CXX_STANDARD 14)

add_executable(EnigmaM3 main.cpp rotor.cpp rotor.h plugboard.cpp plugboard.h reflector.cpp reflector.h model.cpp model.h)