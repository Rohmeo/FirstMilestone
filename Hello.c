#include <stdio.h>
#include <time.h>

int main()
{
	clock_t result1, result2;
	result1 = clock();
	printf("Hello, World!\n");
	result2 = clock();
	result1 = result2-result1;
	printf("Elapsed Time:%d \n",result1);
}
