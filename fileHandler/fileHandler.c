#include "fileHandler.h"


#include <stdio.h>
#include <stdlib.h>


int writeIntoFile(char* fileName,Matrix* matrix){
    FILE* fp = fopen(fileName,"w");
    if(fp == NULL){
        return 1;
    }
    int i = 0;
    while(i<matrix->rows){
        int j = 0;
        while(j<matrix->cols){
            fprintf(fp,"%d\t",matrix->matrix[i][j]);
            j++;
        }
        free(matrix->matrix[i]);
        fprintf(fp,"\n");
        i++;
    }
    fclose(fp);
    return 0;
}


Matrix* readFromFile(char* fileName){
    FILE* fp = fopen(fileName,"r");
    if(fp==NULL){
        return NULL;
    }
    Matrix* mat = malloc(sizeof(*mat));
    int row,col;
    fscanf(fp,"row=%d col=%d",&row,&col);
    mat->rows=row;
    mat->cols=col;
    int** matrix = malloc(row*sizeof(*matrix));
    int i = 0;
    for(;i<row;i++){
        matrix[i] = malloc(col*sizeof(*matrix[i]));
        int j = 0;
        for(;j<col;j++){
            fscanf(fp,"%d",&matrix[i][j]);
        }
    }
    fclose(fp);
    mat->matrix = matrix;
    return mat;
}
