#include<stdlib.h>
#include<stdio.h>
#include<sys/time.h>
#include <time.h>
#include <immintrin.h>

#define ARRAY_SIZE 100000000  // 鏁扮粍澶у皬

int main(){
    int A[ARRAY_SIZE];

    // 璁剧疆闅忔満鏁扮�嶅瓙
    srand(time(NULL));

    // 鐢熸垚闅忔満鏁扮粍
    for (int i = 0; i < ARRAY_SIZE; i++) {
        A[i] = rand() % 100;  // 鐢熸垚 0 鍒� 99 涔嬮棿鐨勯殢鏈烘暟
    }
    int N=sizeof(A)/sizeof(int);
    int T;  //锟斤拷锟斤拷锟斤拷锟斤拷
    int B[ARRAY_SIZE]={0};

    //浼樺寲鍓�
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
    printf("浼樺寲鍓岴lapsed Time: %.6f seconds\n", elapsed_time);

    //浼樺寲鍚�
    int TT[N];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        B[i] = 0;  // 璁剧疆鏁扮粍鍏冪礌涓�0锛屽彲浠ユ牴鎹�闇€瑕佽�剧疆涓哄叾浠栧垵濮嬪€�
    }
    gettimeofday(&start_time, NULL);

    for (int i = 0; i < N; i += 4) {
        // 浣跨敤鎸囬拡璁块棶鏁扮粍鍏冪礌
            
        int* ptr_A = &A[i];
        int* ptr_B = &B[i];
        int* ptr_TT = &TT[i];
        // 浣跨敤SIMD鎸囦护闆嗗姞杞�4涓�鏁存暟鍏冪礌鍒板悜閲忓瘎瀛樺櫒
        __m128i vec_A = _mm_loadu_si128((__m128i*)ptr_A);
        __m128i vec_B = _mm_loadu_si128((__m128i*)ptr_B);

        // 浜ゆ崲鍚戦噺瀵勫瓨鍣ㄤ腑鐨勫厓绱�
        __m128i vec_TT = vec_A;
        vec_A = vec_B;
        vec_B = vec_TT;

        // 灏嗕氦鎹㈠悗鐨勭粨鏋滃瓨鍥炴暟缁�
        _mm_storeu_si128((__m128i*)ptr_A, vec_A);
        _mm_storeu_si128((__m128i*)ptr_B, vec_B);
    }

    gettimeofday(&end_time, NULL);
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    printf("浼樺寲鍚嶦lapsed Time: %.6f seconds\n", elapsed_time);
}
