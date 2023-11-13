#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>

int main(){
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    int x=a[0];
    int N =sizeof(a)/sizeof(int);
    int n;

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    for (int i=1;i<N;i++){
        for(n=0;n<10000000;n++){
            if(a[i]>x){ //S1Óï¾ä
                x=a[i]; //S2Óï¾ä
            }
        }
    }
    
    gettimeofday(&end_time, NULL);
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    printf("Elapsed Time: %.3f seconds\n", elapsed_time);
    printf("x=%d",x);
}