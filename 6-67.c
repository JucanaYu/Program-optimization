#include<stdio.h>
#include<time.h>
int main()
{
	
	// int N = 2;
	// int M = 8;
	// int L = 8;
	const int N = 2;
	const int M = 8;
	const int L = 8;
	int A[N][M][L],B[N][M][L];
	int i,j,k;

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

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
				A[i][j][k-i-j] = A[i][j-1][k-i-j] + A[i-1][j][k-i-j];
				B[i][j][k-i-j+1] = B[i][j][k-i-j] + A[i][j][k-i-j];
			}
		}
	}
	 // 记录结束时间
    gettimeofday(&end_time, NULL);
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    printf("Elapsed Time: %.3f seconds\n", elapsed_time);

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
