#include<stdio.h>
#include<time.h>
int main()
{
	
	int N = 2;
	int M = 8;
	int L = 8;
	// const int N = 2;
	// const int M = 8;
	// const int L = 8;
	int A[N][M][L],B[N][M][L];
	int i,j,k;
	struct timespec start_time, end_time;
	unsigned long long elapsed_time;
	    // 记录开始时间
	clock_gettime(CLOCK_MONOTONIC, &start_time);
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=M;j++)
		{
			for(k=0;k<=L;k++)
			{
				A[i][j][k] = 1;
				B[i][j][k] = 2;
				printf("%d",B[i][j][k]);
			}
		}
	}
	for(i=2;i<N+1;i++)
	{
		for(j=2;j<M+1;j++)
		{
			for(k=i+j+1;k<i+j+L;k++)
			{
				A[i][j][k] = A[i][j-1][k] + A[i-1][j][k];
				B[i][j][k+1] = B[i][j][k] + A[i][j][k];
			}
		}
	}
	 // 记录结束时间
	clock_gettime(CLOCK_MONOTONIC, &end_time);
	    // 计算经过的时间（以纳秒为单位）
	elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000000ULL + (end_time.tv_nsec - start_time.tv_nsec);
	printf("Execution Time: %llu ns\n", elapsed_time);
/*	for(i=0;i<=N;i++)
		for(j=0;j<=M;j++)
		{
			for(k=0;k<=L;k++)
			{
				printf("%d",A[i][j][k]);
			}
			printf("\n");
						
			
		}*/
			
	
	
} 
