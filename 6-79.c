#include<stdio.h>
#include<time.h>

#define N 10

int main(){
    struct timespec start_time, end_time;
    unsigned long long elapsed_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    int A[N]={1,2,3,4,5,6,7,8,9,10};
    int B[N]={1,2,3,4,5,6,7,8,9,10};
    int Y[N]={0};
    int X=1,Z=1,C=1;
    for(int i=1;i<N;i++){
        A[i]=A[i-1]+X;  //S1
        Y[i]=A[i]+Z;    //S2
        A[i]=B[i]+C;    //S3
    }
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000000ULL + (end_time.tv_nsec - start_time.tv_nsec);
    printf("Execution Time: %llu ns\n", elapsed_time);
}