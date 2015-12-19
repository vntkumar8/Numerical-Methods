#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Z 0.00000001
float matrix[10][11];
void display(int );
void nopivot(int );
void pivot(int );
void partial_pivot(int,int );
int maxrow(int,int);
void display(int );
void interchangeRow(int,int,int);
int main(){
	int n,i,j,choice;
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
	printf("\n\n");
	printf("Input choice\n 1. Without partial pivoting\n 2. With partial pivoting\n 3. Exit\n\n Choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        	printf("\t\t\tWithout partial pivoting\n\t\t\t---------------------------\n");
            nopivot(n);
            break;
        case 2:
			printf("\t\t\tWith partial pivoting\n\t\t\t---------------------------\n");
        	pivot(n);
            break;
		case 3:
        	printf("\t\tTerminated!!");
            exit(0);
        default:
            printf("Invalid choice number entered\n");
            exit(2);
    }
	return 0;
}
void display(int n){
	int i,j;
	for(i=1;i<=n;i++){
    	for(j=1;j<=(n+1);j++)
    		printf("%10f   ",matrix[i][j]);
    	printf("\n");
    }
    printf("\n");
}
void nopivot(int n){
	int k,i,j;
	float m[20][20],x[20],sum=0.0;
    	for(k=1;k<=n-1;k++){
    		for(i=k+1;i<=n;i++){		//elimination steps to make upper triangular
			m[i][k]=matrix[i][k]/matrix[k][k];
				for(j=k;j<=n+1;j++){
					matrix[i][j]-=m[i][k]*matrix[k][j];
			}	
			display(n);
		}
		}
		x[n]=matrix[n][n+1]/matrix[n][n];
		for(i=n-1;i>=1;i--){		//back subsutituition steps
			sum=matrix[i][n+1];
			for(j=i+1;j<=n;j++){
				sum-=matrix[i][j]*x[j];
			}
		
			x[i]=sum/matrix[i][i];
		}
		/*solution*/
		for(i=1;i<=n;i++){
    		printf("x%d=%f\n",i,x[i]);
    		
		}
}
void pivot(int n){
	int k,i,j;
	float m[20][20],x[20],sum=0.0;
    	for(k=1;k<=n-1;k++){
    		partial_pivot(k,n);	//pivoting call;
    		for(i=k+1;i<=n;i++){		//elimination steps
			m[i][k]=matrix[i][k]/matrix[k][k];
				for(j=k;j<=n+1;j++){
					matrix[i][j]-=m[i][k]*matrix[k][j];
			}	
			display(n);
		}
		}
		x[n]=matrix[n][n+1]/matrix[n][n];
		for(i=n-1;i>=1;i--){		//back subsutituition steps
			sum=matrix[i][n+1];
			for(j=i+1;j<=n;j++){
				sum-=matrix[i][j]*x[j];
			}
		
			x[i]=sum/matrix[i][i];
		}
		/*solution*/
		for(i=1;i<=n;i++){
    		printf("x%d=%f\n",i,x[i]);
    		
		}
	
}
int maxrow(int k,int n){
	int i,j;float max=matrix[0][k];
	for(i=k;i<=n;i++)
	{
		if(matrix[i][k]>=max){
		max=matrix[i][k];
		j=i;
	    }
    }
    if (max==Z)
	     exit(0);
      	else 
	     return j;
}
void interchangeRow(int a, int b,int n){    
	float temp[n+1];int i;
	for(i=1;i<=n+1;i++){
		temp[i]=matrix[a][i];
		matrix[a][i]=matrix[b][i];
		matrix[b][i]=temp[i];
	}		
	display(n);
}
void partial_pivot(int k,int n){
		int pos= maxrow(k,n);
		if(pos!=k)
		interchangeRow(pos,k,n);	
}
