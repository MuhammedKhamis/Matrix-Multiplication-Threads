#ifndef MATRIX_MULTIPLICATION_THREADS_MEMORYMANGEMENT_H
#define MATRIX_MULTIPLICATION_THREADS_MEMORYMANGEMENT_H

#include "../dataStructures/dataStructure.h"

void freeMatrix(Matrix* matrix);

void freeThread_info(Thread_info* info);

Matrix* getEmptyMatrix(int row,int col);


#endif //MATRIX_MULTIPLICATION_THREADS_MEMORYMANGEMENT_H
