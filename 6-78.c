#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

int main(){
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    int a=3,b=0,y,z,T,T1;
    T=3;    //S1
    for(int n=0;n<1000;n++){
    y=T+T;  //S2
    T1=a-b; //S3
    z=T1*T1;    //S4
    }

    gettimeofday(&end_time, NULL);
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    printf("Elapsed Time: %.3f seconds\n", elapsed_time);

    return 0;
}