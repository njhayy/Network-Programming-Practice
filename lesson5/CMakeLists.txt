cmake_minimum_required(VERSION 3.14)
project(socket_learn C)

set(CMAKE_C_STANDARD 99)

add_executable(server server.c)
add_executable(client client.c)
