#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    struct timespec start_time, end_time;
    unsigned long long elapsed_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    int a =1,b=5;
    int tmp=a+b;
    if(tmp>3 && tmp<10){
        a=tmp;
    }
    // printf("%d",a);

    clock_gettime(CLOCK_MONOTONIC, &end_time);
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000000ULL + (end_time.tv_nsec - start_time.tv_nsec);
    printf("Execution Time: %llu ns\n", elapsed_time);
}