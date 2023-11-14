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
    int T[SIZE];   //标量拓展
    int B[SIZE]={0};

    T[0]= 0;

    for(int i=1;i<N;i++){
            T[i]=A[i];
            A[i]=B[i];
            B[i]=T[i];
    }

    // for(int i=0;i<N;i+=4){
    //     int* ptr_A=&A[i];
    //     int* ptr_B=&B[i];
    //     int* ptr_T;

    //     __m128i vec_A = _mm_loadu_si128((__m128i*)ptr_A);
    //     __m128i vec_B = _mm_loadu_si128((__m128i*)ptr_B);

    //     __m128i vec_T = vec_A;
    //     vec_A =vec_B;
    //     vec_B=vec_T;

    //     _mm_storeu_si128((__m128i*)ptr_A,vec_A);
    //     _mm_storeu_si128((__m128i*)ptr_B,vec_B);
    // }
    
    gettimeofday(&end_time, NULL);
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    printf("Elapsed Time: %.6f seconds\n", elapsed_time);
}