// Solving set of linear equation by Gauss-Jordan elimination method
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float matrix[10][11];
void display(int);
void partial_pivot(int,int);
void pivot(int);
void nopivot(int);
int main(){
    int i,j,k,n,choice;
    printf("Enter the number of variables\n");
    scanf("%d",&n);
    if(n<1){
        printf("Invalid number of equation\n");
        exit(1);
	}
    float multi,sol;
    for(i=0;i<n;i++){
        printf("\nEnter the coefficient of equation %d and its value: ",i+1);
        for(j=0;j<=n;j++)
            scanf("%f",&matrix[i][j]);
    }
    printf("The augmented matrix:\n\n");
    display(n);
    printf("\n\n");
    printf("Input choice\n 1. Without partial pivoting\n 2. With partial pivoting\n 3. Exit\n\n Choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        	printf("\t\t\tWithout partial pivoting\n");
            nopivot(n);
            break;
        case 2:
			printf("\t\t\tWith partial pivoting\n");
        	pivot(n);
            break;
		case 3:
        	printf("\t\tTerminated!!");
            exit(0);
        default:
            printf("Invalid choice number entered\n");
            exit(2);
    }
    printf("The diagonal matrix :\n\n");
    display(n);

    printf("\nThe values of variables are:\n\n");
    for(i=0;i<n;i++){
    	sol=matrix[i][n]/matrix[i][i];
        printf("  x%d = %f\n",i+1,sol);
    }
    return 0;
}
void display(int n){
	int i,j;
	for(i=0;i<n;i++){
    	for(j=0;j<n+1;j++)
    		printf("%10f   ",matrix[i][j]);
    	printf("\n");
    }
}
void nopivot(int n){
	int i,j,k,l,m;
	float multi;
	for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            multi=matrix[j][i]/matrix[i][i];
            for(k=i;k<=n;k++)
                matrix[j][k]=matrix[j][k]-multi*matrix[i][k];
        }
        for(l=0;l<i;l++){
			multi=matrix[l][i]/matrix[i][i];
			for(m=i;m<=n;m++)
				matrix[l][m]=matrix[l][m]-multi*matrix[i][m];
		}
		//printf("after %d step matrix is \n",i+1);
        display(n);
        printf("\n");
    }
}
void pivot(int n){
	int i,j,k,l,m;
	float multi;
	for(i=0;i<n;i++){
		printf("After Step %d matrix is \n",i+1);
        printf("Before pivoting row %d\n",i+1);
        display(n);
        printf("\n");
    	partial_pivot(i,n);
    	printf("After pivoting row %d\n",i+1);
    	display(n);
        printf("\n");
        for(j=i+1;j<n;j++){
            multi=matrix[j][i]/matrix[i][i];
            for(k=i;k<=n;k++)
                matrix[j][k]=matrix[j][k]-multi*matrix[i][k];
        }
        for(l=0;l<i;l++){
			multi=matrix[l][i]/matrix[i][i];
			for(m=i;m<=n;m++)
				matrix[l][m]=matrix[l][m]-multi*matrix[i][m];
		}
    }
}
void partial_pivot(int i,int n){	//function for pivoting
	int j,k;
	float temp;
	for(j=i+1;j<n;j++){
		if(fabs(matrix[i][i])<fabs(matrix[j][i])){
			for(k=0;k<=n;k++){
				temp=matrix[j][k];
				matrix[j][k]=matrix[i][k];
				matrix[i][k]=temp;
			}
		}
	}
}
