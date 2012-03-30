#include <stdio.h>
#include <time.h>
#include <sys/time.h>

typedef struct{
	int width;
	int height;
	int* elements;
} Matrix;

__global__ void matrixProduct(Matrix, Matrix, Matrix);

main()
{
	//Declare vars, constants
	int const MatSize=10; 			//Actual dimension is 1+MatSize
	Matrix Matrix1;
	Matrix1.width = MatSize; Matrix1.height = MatSize;
	Matrix Matrix2;
	Matrix2.width = MatSize; Matrix2.height = MatSize;
	Matrix Result;
	Result.width = MatSize; Result.height = MatSize;
	dim3 blockSize(MatSize,MatSize);
	dim3 gridSize(1,1);

	int i,j;
	struct timeval start, postmem, end;

	//Initialize matrices with random values
	for(i=0;i<=MatSize;i++)
	{
		for(j=0;j<=MatSize;j++)
		{
			Matrix1[i*Matrix1.width+j]=rand();
			Matrix2[i*Matrix1.width+j]=rand();
		}
	}
	gettimeofday(&start,NULL);
	
	//Transfer matrices to device memory
	size_t memSize = MatSize+1 * MatSize+1 * sizeof(int);
	Matrix dev_Matrix1, dev_Matrix2, dev_Result;
	dev_Matrix1.height = Matrix1.height; dev_Matrix1.width = Matrix1.width;
	cudaMalloc(&dev_Matrix1.elements,size);
	cudaMemcpy(dev_Matrix1.elements, Matrix1.elements, size, cudaMemcpyHostToDevice);

	dev_Matrix2.height = Matrix2.height; dev_Matrix2.width = Matrix2.width;
	cudaMalloc(&dev_Matrix2.elements,size);
	cudaMemcpy(dev_Matrix2.elements, Matrix2.elements, size, cudaMemcpyHostToDevice);
	
	dev_Result.height = Result.height; dev_Result.width = Result.width;
	cudaMalloc(&dev_Result.elements,size);
	
		
	//Kernel Declaration
	matrixProduct<<<blockSize,gridSize>>>(dev_Matrix1, dev_Matrix2, dev_Result);
	
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

__global__ void matrixProduct(Matrix Matrix1, Matrix Matrix2, Matrix Result)
{
	int row = threadIdx.x;
	int col = threadIdx.y;
	int k,sum;
	sum=0;
	for(k=0;k<=Matrix1.width;k++)
	{
		sum=sum+(Matrix1[row*Matrix1.width+k]*Matrix2[k*Matrix2.width+col]);
	}
	Result[row*Result.width+col]=sum;
}
