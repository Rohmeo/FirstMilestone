#include <stdio.h>
#include <stdlib.h>




int main(){
	int length, i;
	size_t size;
	
	length = 20;
	size = (length+1)*sizeof(int);
	
	int* Vector1 = malloc(size);
	int* Vector2 = malloc(size);
	int* Result  = malloc(size);
	
	for(i=0;i<=length;i++){
		Vector1[i] = i;
		Vector2[i] = i;
		Result[i]=Vector1[i]+Vector2[i];
	}
	
	for(i=0;i<=length;i++){
		printf("%d\t",Result[i]);
	}
	printf("\n");
	return 0;
}