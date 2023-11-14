#include<stdlib.h>
#include<stdio.h>
#include<sys/time.h>
#include <time.h>
#include <immintrin.h>

#define SIZE 100000

int main(){
    int A[SIZE];

    srand(time(NULL));
   
    //初始化A数组
    for(int i = 0;i<SIZE;i++){
        A[i]=rand()%100;
    }    

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);


    int N=sizeof(A)/sizeof(int);
    int T;   
    int B[SIZE]={0};


    for(int i=1;i<N;i++){
            T=A[i];
            A[i]=B[i];
            B[i]=T;
    }

    gettimeofday(&end_time, NULL);
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    printf("Elapsed Time: %.6f seconds\n", elapsed_time);
}