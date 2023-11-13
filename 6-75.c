#include<stdlib.h>
#include<stdio.h>
#include<sys/time.h>

int main(){
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    int A[10]={1,23,4,26,3,2,6,7,8,5};
    int N=sizeof(A)/sizeof(int);
    int T;  //标量类型
    int B[10]={0};
    for(int i=1;i<N;i++){
        for(int n=0;n<100000000;n++){
            T=A[i];
            A[i]=B[i];
            B[i]=T;
        }
    }

    gettimeofday(&end_time, NULL);
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    printf("Elapsed Time: %.3f seconds\n", elapsed_time);
}