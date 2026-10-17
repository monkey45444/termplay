cmake_minimum_required(VERSION 3.20)
project(termplay)
add_executable(termplay
    src/main.cpp
    src/term.cpp
    src/types.cpp
    src/render.cpp
)
target_include_directories(termplay PRIVATE src)
