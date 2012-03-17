#include <stdio.h>

main()
{
	int Matrix1[9];
	int Matrix2[9];
	int Result[9];
	int i,j;
	
	for(i=1;i<=9;++i)
	{
	        Matrix1[i]=i;
		Matrix2[i]=i;
	}
	Result[1]=(Matrix1[1]*Matrix2[1])+(Matrix1[2]*Matrix2[4])+(Matrix1[3]*Matrix2[7]);
	Result[2]=(Matrix1[1]*Matrix2[2])+(Matrix1[2]*Matrix2[5])+(Matrix1[3]*Matrix2[8]);
	Result[3]=(Matrix1[1]*Matrix2[3])+(Matrix1[2]*Matrix2[6])+(Matrix1[3]*Matrix2[9]);
	Result[4]=(Matrix1[4]*Matrix2[1])+(Matrix1[5]*Matrix2[4])+(Matrix1[6]*Matrix2[7]);
	Result[5]=(Matrix1[4]*Matrix2[2])+(Matrix1[5]*Matrix2[5])+(Matrix1[6]*Matrix2[8]);
	Result[6]=(Matrix1[4]*Matrix2[3])+(Matrix1[5]*Matrix2[6])+(Matrix1[6]*Matrix2[9]);
	Result[7]=(Matrix1[7]*Matrix2[1])+(Matrix1[8]*Matrix2[4])+(Matrix1[9]*Matrix2[7]);
	Result[8]=(Matrix1[7]*Matrix2[2])+(Matrix1[8]*Matrix2[5])+(Matrix1[9]*Matrix2[8]);
	Result[9]=(Matrix1[7]*Matrix2[3])+(Matrix1[8]*Matrix2[6])+(Matrix1[9]*Matrix2[9]);
	
	for(j=1;j<=3;++j)
		printf("%d\t",Result[j]);
	printf("\n");
	for(j=4;j<=6;++j)
		printf("%d\t",Result[j]);
	printf("\n");
        for(j=7;j<=9;++j)
		printf("%d\t",Result[j]);
	printf("\n");
}
