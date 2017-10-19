#include "timeCalculator.h"

#include <sys/time.h>
#include <stdio.h>

void calculateTime(Thread_info* info, int (*functionPtr)(Thread_info*)){

    struct timeval stop, start;
    gettimeofday(&start, NULL); //start checking time

    //your code goes here
    int sz = (*functionPtr)(info);

    gettimeofday(&stop, NULL); //end checking time
    printf("Microseconds taken: %lu\n", stop.tv_usec - start.tv_usec);
    printf("Threads used: %d\n", sz);

}