#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    struct timespec start_time, end_time;
    unsigned long long elapsed_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    int a=3,b=0,y,z,T,T1;
    T=2;
    y=T+T;
    T1=a-b;
    z=T1*T1;
    printf("y=%d z=%d T=%d",y,z,T1);

    clock_gettime(CLOCK_MONOTONIC, &end_time);
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000000ULL + (end_time.tv_nsec - start_time.tv_nsec);
    printf("Execution Time: %llu ns\n", elapsed_time);
}