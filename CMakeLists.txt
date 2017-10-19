cmake_minimum_required(VERSION 3.8)
project(Matrix_Multiplication_Threads)

set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")


set(SOURCE_FILES main.c fileHandler/fileHandler.c fileHandler/fileHandler.h dataStructures/dataStructure.h timeCalculator/timeCalculator.c timeCalculator/timeCalculator.h executers/executers.c executers/executers.h memoryManager/memoryMangement.c memoryManager/memoryMangement.h ThreadMaker/Threadmaker.c ThreadMaker/Threadmaker.h dataStructures/dataStructure.c)
add_executable(Matrix_Multiplication_Threads ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} pthread)
