#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int matrixProduct(int Matrix1[3][3], int Matrix2[3][3], int row, int col, int size);

main()
{
	/*int Matrix1[][];
	int Matrix2[][];
	int Result[][];*/
	int i,j;
	struct timeval start, end;
	int const MatSize = 5;
	size_t size;
	
	size = MatSize*MatSize*sizeof(int);
	
	int* Matrix1[MatSize][MatSize] = malloc(size);
	int* Matrix2[MatSize][MatSize] = malloc(size);
	int* Result[MatSize][MatSize] = malloc(size);
	
	for(i=0;i<=MatSize;i++)
	{
		for(j=0;j<=MatSize;j++)
		{
			Matrix1[i][j]=i+j;
			Matrix2[i][j]=i*j;
		}
	}
	gettimeofday(&start,NULL);
	for(i=0;i<=MatSize;i++)
	{
		for(j=0;j<=MatSize;j++)
		{
		Result[i][j]=matrixProduct(Matrix1,Matrix2,i,j, MatSize);
		}
	}
	gettimeofday(&end,NULL);
	printf("Matrix 1:\n");
	for(i=0;i<=MatSize;i++)
	{
		for(j=0;j<=MatSize;j++)
			printf("%d\t",Matrix1[i][j]);
		printf("\n");
	}
	printf("Matrix 2:\n");
	for(i=0;i<=MatSize;i++)
		{
			for(j=0;j<=MatSize;j++)
				printf("%d\t",Matrix2[i][j]);
			printf("\n");
		}
	printf("Result:\n");
	for(i=0;i<=MatSize;i++)
		{
			for(j=0;j<=MatSize;j++)
				printf("%d\t",Matrix2[i][j]);
			printf("\n");
		}
	printf("Elapsed Time: %d \n",/*((end.tv_sec-start.tv_sec)*1000000)+*/(end.tv_usec-start.tv_usec));
}

int matrixProduct(int *Mat1[MatSize][MatSize], int *Mat2[MatSize][MatSize],int row, int col, int MatSize)
{
	int k,sum;
	sum=0;
	for(k=0;k<=MatSize;k++)
	{
		sum=sum+(Mat1[row][k]*Mat2[k][col]);
	}
	return sum;
}