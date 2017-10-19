#ifndef MATRIX_MULTIPLICATION_THREADS_EXECUTERS_H
#define MATRIX_MULTIPLICATION_THREADS_EXECUTERS_H

#include "../dataStructures/dataStructure.h"



void* computeCell(void* thread_info);

void* computeRow(void* thread_info);

void* computeAll(void* thread_info);


#endif //MATRIX_MULTIPLICATION_THREADS_EXECUTERS_H
