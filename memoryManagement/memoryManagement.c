#include "memoryManagement.h"

#include <stdlib.h>


void freeMatrix(Matrix* matrix){
    int i =0;
    for(;i< (matrix->rows);i++){
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

void freeThread_info(Thread_info* info){
    freeMatrix(info->params.mat1);
    freeMatrix(info->params.mat2);
    freeMatrix(info->res);
    free(info);
}