#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main(){
    struct timespec start_time, end_time;
    unsigned long long elapsed_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    int A[10]={1,23,4,26,3,2,6,7,8,5};
    int N=sizeof(A)/sizeof(int);
    int T[N];   //±Í¡øÕÿ’π
    int B[10]={0};
    for(int i=1;i<N;i++){
        T[i]=A[i];
        A[i]=B[i];
        B[i]=T[i];
    }

    clock_gettime(CLOCK_MONOTONIC, &end_time);
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000000ULL + (end_time.tv_nsec - start_time.tv_nsec);
    printf("Execution Time: %llu ns\n", elapsed_time);
}