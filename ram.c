#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>

#define MB 1024*1024
#define GB 1024*MB
#define SIZE 3*GB  
#define LENG 1000  //40G
#define CHUNK 40*MB

clock_t start, end;
char * p[LENG];

int main(int argc, char const *argv[])
{
	size_t totalSize = 0;
	int i =0;
	double lastTime = 0;
	double currentTime = 0;
	for(i=0;i<LENG;i++){
		start = clock();
		p[i] = malloc(CHUNK);
		int j=0;
		for(j=0;j<i;j++){
			memset(p[j],0,CHUNK);
		}
		end = clock();

		currentTime = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("%f %lu\n", currentTime, totalSize/(MB));
		if(lastTime!=0 && currentTime > lastTime*2 && i>9){
			break;
		}
		totalSize += CHUNK;
		lastTime = currentTime;
	}
	printf("totalSize: %luMB\n", totalSize/(MB));
	return 0;
}