#include <stdio.h>
#include <sys/time.h>

int main() {
    // 记录开始时�?
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

	//。。。代码部�?

    // 记录结束时间
    gettimeofday(&end_time, NULL);
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    printf("Elapsed Time: %.3f seconds\n", elapsed_time);

    return 0;
}
