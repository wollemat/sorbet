project(sorbet)

set(CMAKE_C_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH  "../bin")

add_executable(sorbet src/main.c)
