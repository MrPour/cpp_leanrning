#声明要求的cmake最低版本
cmake_minimum_required(VERSION 3.0)
#声明一个工程
project(C__learning)

set(CMAKE_CXX_STANDARD 14)

#语法： add_executable(程序名 源代码文件)
add_executable(C__learning template/VectorTemplate.cpp)
