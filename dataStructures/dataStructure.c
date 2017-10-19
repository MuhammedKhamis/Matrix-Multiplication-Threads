#include "dataStructure.h"

#include <stdlib.h>
#include <memory.h>

Matrix* getEmptyMatrix(int row , int col){
    Matrix* tmp = malloc(sizeof(*tmp));
    tmp->rows=row;
    tmp->cols=col;
    tmp->matrix = malloc(row*sizeof(*(tmp->matrix)));
    int i = 0;
    for(;i<row;i++){
        tmp->matrix[i] = malloc(col*sizeof(*(tmp->matrix[i])));
        memset(tmp->matrix[i],0,col*sizeof(*(tmp->matrix[i])));
    }
    return tmp;
}
