#include <stdio.h>
#include <stdlib.h>


__global__ void VecAdd(int *Vec1, int *Vec2, int *Res){
	Res[threadIdx.x]=Vec1[threadIdx.x]+Vec2[threadIdx.x];
}

int main(){
	int length, i;
	size_t size;
	
	length = 10;
	size = (length+1)*sizeof(int);
	
	int* Vector1 = malloc(size);
	int* Vector2 = malloc(size);
	int* Result  = malloc(size);
	
	for(i=0;i<=length;i++){
		Vector1[i] = i;
		Vector2[i] = i;
	}
	cudaMalloc(&dev_Vector1, size);
	cudaMalloc(&dev_Vector2, size);
	cudaMalloc(&dev_Result, size);
	
	cudaMemcpy(&dev_Vector1,Vector1,size,cudaMemcpyHostToDevice);
	cudaMemcpy(&dev_Vector2,Vector2,size,cudaMemcpyHostToDevice);
	VecAdd<<<length+1,1>>>(dev_Vector1, dev_Vector2, dev_Result);
	
	cudaMemcpy(&Result, dev_Result, size, cudaMemcpyDeviceToHost);
	
	for(i=0;i<=length;i++){
		printf("%d\t",Result[i]);
	}
	printf("\n");
	return 0;
}