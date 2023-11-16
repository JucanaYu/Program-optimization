#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

int main(){
    int a =1,b=5;
    int tmp=a+b;

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    int sum = 0;
    while ( sum < 10000000)
    {
        if(tmp>3 && tmp<10){
            sum++;
        }
    }
    
    // printf("%d",a);

    gettimeofday(&end_time, NULL);
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    printf("Elapsed Time: %.6f seconds\n", elapsed_time);

    return 0;
}