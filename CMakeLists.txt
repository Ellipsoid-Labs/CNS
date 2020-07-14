cmake_minimum_required(VERSION 3.10)
project(CNS VERSION "0.0.1")

configure_file(makeconfig.h.in makeconfig.h)
add_executable(CNS main.cpp)
target_include_directories(CNS PUBLIC "${PROJECT_BINARY_DIR}")
