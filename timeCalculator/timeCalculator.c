#include "timeCalculator.h"

#include <sys/time.h>
#include <stdio.h>

void calculateTime(Thread_info* info, int (*functionPtr)(Thread_info*)){

    struct timeval stop, start;
    gettimeofday(&start, NULL); //start checking time

    //your code goes here
    int sz = (*functionPtr)(info);

    gettimeofday(&stop, NULL); //end checking time
    if(sz == -1){
        fprintf(stderr,"Can't generate that number of threads for this method\n");
    }else {
        printf("Microseconds taken: %lu\n", stop.tv_usec - start.tv_usec);
        printf("Threads used: %d\n", sz);
    }
    printf("-----------------------------------------------------\n");

}