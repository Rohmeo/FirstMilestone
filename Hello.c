#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main()
{
	struct timeval tv1, tv2;
	int i;
	time_t sec, usec;
	
	gettimeofday(&tv1, NULL);
	printf("Hello, World!\n");
	for(i=0;i<=500000;i++);
	gettimeofday(&tv2, NULL);
	sec=tv2.tv_sec-tv1.tv_sec;
	usec=tv2.tv_usec-tv1.tv_usec;
	
	printf("Elapsed Time: %d \n",usec+(1000000*sec));
}
