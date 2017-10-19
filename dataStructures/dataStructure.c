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
        size_t sz = col*sizeof(**(tmp->matrix));
        tmp->matrix[i] = malloc(sz);
        memset(tmp->matrix[i],0,sz);
    }
    return tmp;
}
