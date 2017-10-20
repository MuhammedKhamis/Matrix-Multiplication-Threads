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

const char* defaultSrc1= "a.txt";
const char* defaultSrc2= "b.txt";
const char* defaultDest= "c";


int main(int argc , char* argv[]) {
    char src1[MAX_FILE_NAME_SIZE]={'\0'};
    char src2[MAX_FILE_NAME_SIZE]={'\0'};
    char dest1[MAX_FILE_NAME_SIZE]={'\0'};
    char dest2[MAX_FILE_NAME_SIZE]={'\0'};
    if(argc > 1){
        strcat(src1,argv[1]);
        strcat(src2,argv[2]);
        strcat(dest1,argv[3]);
        strcat(dest2,argv[3]);
    }else{
        strcat(src1,defaultSrc1);
        strcat(src2,defaultSrc2);
        strcat(dest1,defaultDest);
        strcat(dest2,defaultDest);
    }
    Thread_info* info = malloc(sizeof(*info));
    info->params.mat1= readFromFile(src1);
    info->params.mat2= readFromFile(src2);
    //
        if(info->params.mat2->rows != info->params.mat1->cols){
            fprintf(stderr,"Mismatch in the sizes of the two input arrays\n");
            exit(1);
        }
    //
    //////////////////////// For Debugging ///////////////////////////
    printMatrix(info->params.mat1);
    ////////////////////////////////////////////////////
    if(!calculateTime(info,&threadByCell))
        writeIntoFile(strcat(dest1,"_1"),info->res);
    if(!calculateTime(info,&threadByRow))
        writeIntoFile(strcat(dest2,"_2"),info->res);
    //calculateTime(info,&threadByMatrix);
    freeThread_info(info);
}