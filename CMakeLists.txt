cmake_minimum_required(VERSION 3.17)
project(hilibuv)
add_executable(hilibuv tty_main.cpp)

# 设置 LIBUVDIR 路径 /path/libuv
# set(LIBUVDIR /path/libuv)
include_directories(${LIBUVDIR}/src)
include_directories(${LIBUVDIR}/include)

# libuv_a.a 是libuv的静态链接库
# 
add_library(libuv STATIC IMPORTED)
set_target_properties(libuv
        PROPERTIES IMPORTED_LOCATION
        ${LIBUVDIR}/build/libuv_a.a)

#add_definitions("--./1.txt")

target_link_libraries(hilibuv libuv)
