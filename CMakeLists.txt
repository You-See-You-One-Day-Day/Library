cmake_minimum_required(VERSION 3.17)
project(Library)

set(CMAKE_CXX_STANDARD 20)

add_library(library Administrator.cpp CommonUser.cpp User.cpp Library.cpp Book.cpp)

add_executable(main main.cpp)

target_link_libraries(main library)
