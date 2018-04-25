#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#define KB 1024
#define MB 1024 * KB
#define TIMES 1000
#define BILLION 1000000000L

int arraysizes[] = {1 * KB, 4 * KB, 8 * KB, 16 * KB,
			   32 * KB, 64 * KB, 128 * KB, 256 * KB,
    		   512 * KB, 1 * MB, 1.5 * MB, 2 * MB, 
			   2.5 * MB, 3 * MB, 3.5 * MB, 4 * MB,
			   8 * MB, 16 * MB};
int N = (sizeof(arraysizes)/sizeof(int)); //len(arraysizes[])




float measure(int ArraySize,int Stride){
	// clock_t start, end;
	struct timespec start, stop;
	uint64_t diff;

	double time_used;

	int *array= malloc(sizeof(int)*ArraySize);
	// start = clock();
	clock_gettime( CLOCK_REALTIME, &start);

	int times = 0;
	for (times = 0; times < TIMES; times++){
		int i=0;
	 	for (i=0; i < ArraySize; i = i + Stride){
	 	    array[i]++;
	 	} 
	}
	//end = clock();
	clock_gettime( CLOCK_REALTIME, &stop);

	//printf("ticks: %f clocksps: %ld\n", (double) (end - start),CLOCKS_PER_SEC);
	//time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    time_used = (double)(stop.tv_sec - start.tv_sec ) + (double)(stop.tv_nsec - start.tv_nsec)/1000000000L;
    // diff = BILLION * (stop.tv_sec - start.tv_sec) + stop.tv_nsec - start.tv_nsec;
    // printf("time = %llu ns\n", (long long unsigned int) diff);
    // printf("s: %llu  ns: %llu time: %lf\n",(stop.tv_sec - start.tv_sec ) , ( stop.tv_nsec - start.tv_nsec ),time_used);
	time_used = time_used*1000/(ArraySize/Stride); //TIMES operation average time (ms)
	free(array);
	return time_used;
}


int main(int argc, char const *argv[])
{	
	int i=0; //arraysize
	for(i =0; i<N; i++){
		int stride=0;
		printf("y%d=[\n", i);
		for(stride = 1; stride<=arraysizes[i]/2; stride*=2){
			// printf("stride: %d\n", stride);
			double runtime = measure(arraysizes[i],stride);
			printf("%f", runtime);
			if (!(stride*2>arraysizes[i]/2)){printf(",");}
		}
		printf("]\n");
		// printf("=======size:%d=======\n",arraysizes[i]/(KB));
	}
	return 0;
}