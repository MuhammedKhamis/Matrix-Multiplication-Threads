#ifndef MATRIX_MULTIPLICATION_THREADS_THREADMAKER_H
#define MATRIX_MULTIPLICATION_THREADS_THREADMAKER_H

#include "../dataStructures/dataStructure.h"

int threadByCell(Thread_info* info);

int threadByRow(Thread_info* info);

int threadByMatrix(Thread_info* info);


#endif //MATRIX_MULTIPLICATION_THREADS_THREADMAKER_H
