#include<stdlib.h>
#include<stdio.h>
#include<sys/time.h>
#include <time.h>
#include <immintrin.h>

#define ARRAY_SIZE 100000000  // 数组大小

int main(){
    int A[ARRAY_SIZE];

    // 设置随机数种子
    srand(time(NULL));

    // 生成随机数组
    for (int i = 0; i < ARRAY_SIZE; i++) {
        A[i] = rand() % 100;  // 生成 0 到 99 之间的随机数
    }
    int N=sizeof(A)/sizeof(int);
    int T;  //��������
    int B[ARRAY_SIZE]={0};

    //优化前
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    /*
    int A[10]={1,23,4,26,3,2,6,7,8,5};
    */

    for(int i=0;i<N;i++){
        T=A[i];
        A[i]=B[i];
        B[i]=T;
    }
    
    gettimeofday(&end_time, NULL);
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    printf("优化前Elapsed Time: %.6f seconds\n", elapsed_time);

    //优化后
    int TT[N];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        B[i] = 0;  // 设置数组元素为0，可以根据需要设置为其他初始值
    }
    gettimeofday(&start_time, NULL);

    for (int i = 0; i < N; i += 4) {
        // 使用指针访问数组元素
            
        int* ptr_A = &A[i];
        int* ptr_B = &B[i];
        int* ptr_TT = &TT[i];
        // 使用SIMD指令集加载4个整数元素到向量寄存器
        __m128i vec_A = _mm_loadu_si128((__m128i*)ptr_A);
        __m128i vec_B = _mm_loadu_si128((__m128i*)ptr_B);

        // 交换向量寄存器中的元素
        __m128i vec_TT = vec_A;
        vec_A = vec_B;
        vec_B = vec_TT;

        // 将交换后的结果存回数组
        _mm_storeu_si128((__m128i*)ptr_A, vec_A);
        _mm_storeu_si128((__m128i*)ptr_B, vec_B);
    }

    gettimeofday(&end_time, NULL);
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    printf("优化后Elapsed Time: %.6f seconds\n", elapsed_time);
}
