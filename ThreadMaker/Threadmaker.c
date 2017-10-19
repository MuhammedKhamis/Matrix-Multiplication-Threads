#include "Threadmaker.h"
#include "../executers/executers.h"

#include <pthread.h>
#include <stdlib.h>

int threadByCell(Thread_info* info){
    int sz = info->params.mat1->rows*info->params.mat2->cols;
    info->res=getEmptyMatrix(info->params.mat1->rows,info->params.mat2->cols);
    void* status;
    Thread_info* tmp;
    pthread_t threads[sz];
    int i=0;
    for(;i<sz;i++){
        tmp = malloc(sizeof(*tmp));
        tmp->res = info->res;
        tmp->params=info->params;
        tmp->params.row = (i/info->params.mat1->rows);
        tmp->params.col = (i%info->params.mat1->rows);
        int rc = pthread_create(&threads[i], NULL, computeCell, (void *)tmp);
        if (rc){
            exit(-1);
        }
    }
    for(i=0;i<sz;i++){
        pthread_join(threads[i],&status);
        free(status);
    }
    return sz;

}

int threadByRow(Thread_info* info){
    int sz = info->params.mat1->rows;
    info->res=getEmptyMatrix(info->params.mat1->rows,info->params.mat2->cols);
    pthread_t threads[sz];
    void* status;
    Thread_info* tmp;
    int i=0;
    for(;i<sz;i++){
        tmp = malloc(sizeof(*tmp));
        tmp->res = info->res;
        tmp->params=info->params;
        tmp->params.row=i;
        int rc = pthread_create(&threads[i], NULL, computeRow, (void *)tmp);
        if (rc){
            exit(-1);
        }
    }
    for(i=0;i<sz;i++){
        pthread_join(threads[i],&status);
        free(status);
    }
    return sz;
}


int threadByMatrix(Thread_info* info){
    pthread_t thread;
    info->res=getEmptyMatrix(info->params.mat1->rows,info->params.mat2->cols);
    int rc = pthread_create(&thread, NULL, computeAll, (void *)info);
    if (rc){
        exit(-1);
    }
    pthread_join(thread,NULL);
    return 1;
}