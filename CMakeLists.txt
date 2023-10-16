cmake_minimum_required(VERSION 3.26)
project(lowLevelLove C)

set(CMAKE_C_STANDARD 11)

add_executable(lowLevelLove
        "src/(lab1)envVariables1.c"
        src/32Bit_64Bit_example.c
        src/envVariables0.c
        src/findAllEven.c
        src/findAvgArgs.c
        src/findMinArgs.c
        src/staticAddressing.c
        src/threadProgramming0.c
        src/threadProgramming1.c
        src/threadProgramming2.c)
