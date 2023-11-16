#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>


#define N 100000

int main(){
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    int A[N];
    int B[N];

    for(int i=0;i<N;i++){
        A[i]=rand()%100;
    }
    for(int i=0;i<N;i++){
        B[i]=rand()%100;
    }
    int Y[N]={0};
    int X=1,Z=1,C=1;
    for(int i=1;i<N;i++){
        A[i]=A[i-1]+X;  //S1
        Y[i]=A[i]+Z;    //S2
        A[i]=B[i]+C;    //S3
    }

    gettimeofday(&end_time, NULL);
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    printf("Elapsed Time: %.6f seconds\n", elapsed_time);

    return 0;
}