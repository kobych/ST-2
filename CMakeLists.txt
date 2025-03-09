cmake_minimum_required(VERSION 3.10.2)
project(ST-2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g")

# Устанавливаем пути для выходных файлов
set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "include/")

# Добавляем Google Test через FetchContent
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Добавляем поддиректории src и test
add_subdirectory(src)
add_subdirectory(test)
