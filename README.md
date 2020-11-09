This is used to learn `libuv`.

If you want to run it, please add a `CMakeLists.txt` file.

```
cmake_minimum_required(VERSION 3.17)
project(hilibuv)
add_executable(hilibuv main.cpp)

# set LIBUVDIR path, for example '/path/libuv'
set(LIBUVDIR /path/libuv)
include_directories(${LIBUVDIR}/src)
include_directories(${LIBUVDIR}/include)

# libuv_a.a is a statically-linked library of libuv
# reference https://mlib.wang/2020/09/28/debug-libuv/
add_library(libuv STATIC IMPORTED)
set_target_properties(libuv
        PROPERTIES IMPORTED_LOCATION
        ${LIBUVDIR}/build/libuv_a.a)

target_link_libraries(hilibuv libuv)
```
