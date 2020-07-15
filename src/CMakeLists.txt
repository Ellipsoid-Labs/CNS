cmake_minimum_required(VERSION 3.10)
project(CNS VERSION "1.0.0")

add_executable(CNS interpreter.cpp main.cpp)
target_include_directories(CNS PUBLIC "${PROJECT_BINARY_DIR}/src")
