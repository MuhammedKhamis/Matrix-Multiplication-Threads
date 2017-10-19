#include "dataStructures/dataStructure.h"
#include "fileHandler/fileHandler.h"
#include "ThreadMaker/Threadmaker.h"
#include "timeCalculator/timeCalculator.h"
#include "memoryManager/memoryMangement.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc , char* argv[]) {
    char src1[20]={'\0'};
    char src2[20]={'\0'};
    char dest1[20]={'\0'};
    char dest2[20]={'\0'};
    if(argc > 1){
        strcat(src1,argv[1]);
        strcat(src2,argv[2]);
        strcat(dest1,argv[3]);
        strcat(dest2,argv[3]);
    }else{
        strcat(src1,"a.txt");
        strcat(src2,"b.txt");
        strcat(dest1,"c");
        strcat(dest2,"c");
    }
    Thread_info* info = malloc(sizeof(info));
    info->params.mat1= readFromFile(src1);
    info->params.mat2= readFromFile(src2);
    calculateTime(info,&threadByCell);
    writeIntoFile(strcat(dest1,"_1"),info->res);
    calculateTime(info,&threadByRow);
    writeIntoFile(strcat(dest2,"_2"),info->res);
    //calculateTime(info,&threadByMatrix);
    //freeThread_info(info);
}