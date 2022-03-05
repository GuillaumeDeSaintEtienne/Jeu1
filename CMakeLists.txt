cmake_minimum_required(VERSION 3.17)
project(Jeu1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Jeu1 main.c jeu.c)

target_link_libraries(Jeu1 -lmingw32 -lallegro-5.0.10-monolith-md-debug)