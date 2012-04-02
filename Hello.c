#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

int main()
{
	struct timeval tv1, tv2;
	int i;
	int Matrix[3][3];
	int *matAddress;
	
	int size = 3*3*sizeof(int);
	
	matAddress = (int*) malloc(size);
	
	
	time_t sec, usec;
	gettimeofday(&tv1, NULL);
	printf("Hello, World!\n");
	for(i=0;i<=500000;i++);
	gettimeofday(&tv2, NULL);
	sec=tv2.tv_sec-tv1.tv_sec;
	usec=tv2.tv_usec-tv1.tv_usec;
	
	printf("Elapsed Time: %d \n",usec+(1000000*sec));
	printf("Integer:%d\n%d\n%d\n",rand(),rand(),rand());
}
