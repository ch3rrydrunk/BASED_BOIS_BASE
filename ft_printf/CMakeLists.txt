cmake_minimum_required(VERSION 3.2)

set(NAME ft_printf)
project(${NAME} C)

file(GLOB SRC src/*.c)
add_library(${NAME} STATIC ${SRC})
target_include_directories(${NAME} PRIVATE include)
target_compile_options(${NAME} PRIVATE -Wall -Wextra -Werror )#-Wno-error=misleading-indentation -Wno-misleading-indentation)
add_subdirectory (tests)
