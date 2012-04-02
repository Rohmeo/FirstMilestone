#include <stdio.h>
#include <time.h>
#include <sys/time.h>


__global__ void matrixProduct(int *Mat1[MatSize][MatSize], int *Mat2[MatSize][MatSize], int *Res[MatSize][MatSize]);
{
	int row = threadIdx.x;
	int col = threadIdx.y;
	int k,sum;
	sum=0;
	for(k=0;k<=MatSize;k++)
	{
		sum=sum+(Mat1[row][k]*Mat2[k][col]);
	}
	Res[row][col]=sum;
}



main()
{
	//Declare vars, constants
	int const MatSize; 			
	int Matrix1[MatSize][MatSize];
	int Matrix2[MatSize][MatSize];
	int Result[MatSize][MatSize];
	int i,j;
	int *dev_Matrix1[MatSize][MatSize];
	struct timeval start, end;

	//Initialize matrices with random values
	MatSize = 10;
	for(i=0;i<=MatSize;i++)
	{
		for(j=0;j<=MatSize;j++)
		{
			Matrix1[i][j]=rand();
			Matrix2[i][j]=rand();
		}
	}
	gettimeofday(&start,NULL);
	
	//Transfer matrices to device memory
	size_t memSize = MatSize * MatSize * sizeof(int);
	
	
	__loadToShared
	//Kernel Declaration
	dim3 blockSize(MatSize,MatSize);
	dim3 gridSize(1,1);
	matrixProduct<<<blockSize,gridSize>>>()
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