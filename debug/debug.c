#include "debug.h"

#include <stdio.h>

void printMatrix(Matrix* matrix){
    int i = 0;
        for(;i<matrix->rows;i++){
            int j=0;
            for(;j<matrix->cols;j++){
                printf("%d ",matrix->matrix[i][j]);
            }
            printf("\n");
        }
}
