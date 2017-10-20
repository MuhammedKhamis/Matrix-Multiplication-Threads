#include "timeCalculator.h"

#include <sys/time.h>
#include <stdio.h>

int calculateTime(Thread_info* info, int (*functionPtr)(Thread_info*)){

    struct timeval stop, start;
    int returnValue=0;
    gettimeofday(&start, NULL); //start checking time

    //your code goes here
    int sz = (*functionPtr)(info);

    gettimeofday(&stop, NULL); //end checking time
    if(sz == -1){
        fprintf(stderr,"Can't generate that number of threads for this method\n");
        returnValue=sz;
    }else {
        printf("Microseconds taken: %lu\n", stop.tv_usec - start.tv_usec);
        printf("Seconds taken %lu\n", stop.tv_sec - start.tv_sec);
        printf("Threads used: %d\n", sz);
    }
    printf("-----------------------------------------------------\n");
    return returnValue;
}