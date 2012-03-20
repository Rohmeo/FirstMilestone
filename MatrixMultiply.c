#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int matrixProduct(int Matrix1[3][3], int Matrix2[3][3], int row, int col);

main()
{
	int Matrix1[3][3];
	int Matrix2[3][3];
	int Result[3][3];
	int i,j;
	struct timeval start, end;
	
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			Matrix1[i][j]=i+j;
			Matrix2[i][j]=i*j;
		}
	}
	gettimeofday(&start,NULL);
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
		Result[i][j]=matrixProduct(Matrix1,Matrix2,i,j);
		}
	}
	gettimeofday(&end,NULL);
	printf("Matrix 1:\n");
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
			printf("%d\t",Matrix1[i][j]);
		printf("\n");
	}
	printf("Matrix 2:\n");
	for(i=0;i<=2;i++)
		{
			for(j=0;j<=2;j++)
				printf("%d\t",Matrix2[i][j]);
			printf("\n");
		}
	printf("Result:\n");
	for(i=0;i<=2;i++)
		{
			for(j=0;j<=2;j++)
				printf("%d\t",Matrix2[i][j]);
			printf("\n");
		}
	printf("Elapsed Time: %d \n",/*((end.tv_sec-start.tv_sec)*1000000)+*/(end.tv_usec-start.tv_usec));
}

int matrixProduct(int Matrix1[3][3], int Matrix2[3][3],int row, int col)
{
	int k,sum;
	sum=0;
	for(k=0;k<=2;k++)
	{
		sum=sum+(Matrix1[row][k]*Matrix2[k][col]);
	}
	return sum;
}