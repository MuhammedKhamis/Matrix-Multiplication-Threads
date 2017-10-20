#include "dataStructures/dataStructure.h"
#include "fileHandler/fileHandler.h"
#include "threadMaker/threadMaker.h"
#include "timeCalculator/timeCalculator.h"
#include "memoryManagement/memoryManagement.h"
#include "constants/constants.h"
#include "debug/debug.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const char* defaultValues[]  = {"a.txt","b.txt","c"};

void setValue(char* dest,char* argv[],int argc, int i){

    if(argc > i){
        strcat(dest,argv[i]);
    }else{
        strcat(dest,defaultValues[i-1]);
    }
}


int main(int argc , char* argv[]) {
    char val[4][MAX_FILE_NAME_SIZE]={'\0'};
    int i = 1;
    for(;i<4;i++){
     setValue(val[i-1],argv,argc,i);
    }
    setValue(val[3],argv,argc,3);
    Thread_info* info = malloc(sizeof(*info));
    info->params.mat1= readFromFile(val[0]);
    info->params.mat2= readFromFile(val[1]);
    //
        if(info->params.mat2->rows != info->params.mat1->cols){
            fprintf(stderr,"Mismatch in the sizes of the two input arrays\n");
            exit(1);
        }
    //
    if(!calculateTime(info,&threadByCell))
        writeIntoFile(strcat(val[2],"_1"),info->res);
    if(!calculateTime(info,&threadByRow))
        writeIntoFile(strcat(val[3],"_2"),info->res);
    freeThread_info(info);
}