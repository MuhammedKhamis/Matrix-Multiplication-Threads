#include "memoryManagement.h"

#include <stdlib.h>
#include <memory.h>


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

Matrix* getEmptyMatrix(int row , int col){
    Matrix* tmp = malloc(sizeof(*tmp));
    tmp->rows=row;
    tmp->cols=col;
    tmp->matrix = malloc(row*sizeof(*(tmp->matrix)));
    int i = 0;
    for(;i<row;i++){
        size_t sz = col*sizeof(**(tmp->matrix));
        tmp->matrix[i] = malloc(sz);
        memset(tmp->matrix[i],0,sz);
    }
    return tmp;
}