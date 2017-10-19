#include "executers.h"


void* computeCell(void* thread_info){
    Thread_info* info = (Thread_info*)thread_info;
    int i = 0;
    for(;i< info->params.mat1->cols;i++){
        info->res->matrix[info->params.row][info->params.col]
                += info->params.mat1->matrix[info->params.row][i]
                   *info->params.mat2->matrix[i][info->params.col];
    }
    return thread_info;
}

void* computeRow(void* thread_info){
    Thread_info* info = (Thread_info*) thread_info;
    int j = 0;
    for(;j<info->params.mat2->cols;j++){
        info->params.col=j;
        computeCell(info);
    }
    return thread_info;

}
void* computeAll(void* thread_info){
    Thread_info* info = (Thread_info*) thread_info;
    int k = 0;
    for(;k<info->params.mat1->rows;k++){
        info->params.row=k;
        computeRow(thread_info);
    }
    return thread_info;
}
