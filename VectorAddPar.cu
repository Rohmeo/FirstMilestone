#include <stdio.h>
#include <stdlib.h>


__global__ void VecAdd(int *Vec1, int *Vec2, int *Res){
	Res[blockIdx.x]=Vec2[blockIdx.x]+Vec2[blockIdx.x];
}

int main(){
	int length, i;
	size_t size;
	int *dev_Vector1;
	int *dev_Vector2;
	int *dev_Result;
	
	length = 10;
	size = (length+1)*sizeof(int);
	
	int* Vector1 = (int*)malloc(size);
	int* Vector2 = (int*)malloc(size);
	int* Result  = (int*)malloc(size);
	
	for(i=0;i<=length;i++){
		Vector1[i] = i;
		Vector2[i] = i;
	}
	cudaMalloc((void**)&dev_Vector1, size);
	cudaMalloc((void**)&dev_Vector2, size);
	cudaMalloc((void**)&dev_Result, size);
	
	cudaMemcpy(dev_Vector1,Vector1,size,cudaMemcpyHostToDevice);
	cudaMemcpy(dev_Vector2,Vector2,size,cudaMemcpyHostToDevice);
	VecAdd<<<length+1,1>>>(dev_Vector1, dev_Vector2, dev_Result);
	
	cudaMemcpy(Result, dev_Result, size, cudaMemcpyDeviceToHost);
	
	for(i=0;i<=length;i++){
		printf("%d\t",Result[i]);
	}
	printf("\n");
	free(Vector1);
	free(Vector2);
	free(Result);
	cudaFree(dev_Vector1);
	cudaFree(dev_Vector2);
	cudaFree(dev_Result);
	return 0;
}
