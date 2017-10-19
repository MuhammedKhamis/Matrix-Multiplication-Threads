#ifndef MATRIX_MULTIPLICATION_THREADS_FILEHANDLER_H
#define MATRIX_MULTIPLICATION_THREADS_FILEHANDLER_H

#include "../dataStructures/dataStructure.h"

typedef int type;


int writeIntoFile(char* fileName, Matrix* matrix);

Matrix* readFromFile(char* fileName);

#endif //MATRIX_MULTIPLICATION_THREADS_FILEHANDLER_H
