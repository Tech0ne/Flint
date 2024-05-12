cmake_minimum_required(VERSION 3.17)

project(flint)

set(
    CMAKE_CXX_STANDARD 20
)

set(CMAKE_CXX_FLAGS -rdynamic)

add_compile_options(
    -Wall -Wextra -Werror -g3
)

# add_library(flint
#   SHARED
add_executable(flint
    src/Colors.cpp
    src/CxxABI.cpp
    src/Exceptions.cpp
    # src/Json.cpp
    src/main.cpp
)

target_include_directories(flint
    PRIVATE
        ${PROJECT_SOURCE_DIR}/includes/
)
