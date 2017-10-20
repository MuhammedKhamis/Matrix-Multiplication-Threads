#ifndef MATRIX_MULTIPLICATION_THREADS_TIMECALCULATOR_H
#define MATRIX_MULTIPLICATION_THREADS_TIMECALCULATOR_H

#include "../dataStructures/dataStructure.h"

typedef int (*functionPtr)(Thread_info*);


int calculateTime(Thread_info* info, int (*functionPtr)(Thread_info*));


#endif //MATRIX_MULTIPLICATION_THREADS_TIMECALCULATOR_H
