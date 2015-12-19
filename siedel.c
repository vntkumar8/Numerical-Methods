#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Z 0.00000001
int main(){
	int n,i,j,choice;
	int converging=0;
	printf("\t Input the Number of Variables in the Equation: ");
	scanf("%d",&n);
	if(n<1){
        printf("Invalid number of equation\n");
        exit(1);
	}
	for(i=1;i<=n;i++){
		printf("Enter the Co-efficent of %d equation: ",i);
		for(j=1;j<=(n+1);j++){
			scanf("%f",&matrix[i][j]);
		}
	}
	printf("\n Input Matrix is :\n ");
	display(n);
	printf("\n\n-----------------------------------------------------------------------\n");
	
    }
	return 0;
	for(i=1;i<=n;i++)
        {
        	for(j=1;j<=(n+1);j++)
        	{
        		if(matrix[i][i]<matrix[i][j])
        			converging=1;
        	}
        }
        if(converging=1)
        printf("No Solution Exists!\n");
       
}
