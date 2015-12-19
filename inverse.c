/*  finding the inverse of matrix using Gauss-Jordan Elimination method*/

#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#define maximum 10
#define minvalue 0.0005

int main(){
 	float matrix[maximum][2*maximum] ;    
 	float temporary, r ;
 	int i, j, k, n, temp;     
 	printf("\n  INVERSE OF NON-SINGULAR MATRIX BY GAUSS-JORDAN ELIMINATION  METHOD");
 	printf("\n Enter the dimension of the matrix to be provided as input : ");
 	scanf("%d",&n);

 	printf("\n Enter a non-singular %dx%d matrix : \n",n,n);
 	for(i=0; i<n; i++)
  	for(j=0; j<n; j++)
            scanf("%f",&matrix[i][j]) ;

 	for(i=0;i<n; i++)
  	for(j=n; j<2*n; j++)
      if(i==j%n)
         matrix[i][j]=1;
      else
         matrix[i][j]=0;
 /* using gauss-jordan elimination */
 	for(j=0; j<n; j++){
  	temp=j;
  	for(i=j+1; i<n; i++)
	if(matrix[i][j]>matrix[temp][j])
                        temp=i;
  	if(fabs(matrix[temp][j])<minvalue){
                printf("\n Elements are too small to deal with !!!");
                exit(1);
             }

  	if(temp!=j)
            for(k=0; k<2*n; k++){
            temporary=matrix[j][k] ;
            matrix[j][k]=matrix[temp][k] ;
            matrix[temp][k]=temporary ;
            }

  	for(i=0; i<n; i++)
            if(i!=j){
            r=matrix[i][j];
            for(k=0; k<2*n; k++)
              matrix[i][k]-=(matrix[j][k]/matrix[j][j])*r ;
            }
            else{
            r=matrix[i][j];
            for(k=0; k<2*n; k++)
              matrix[i][k]/=r ;
            }
 }
 	printf("\n After Gauss-Jordan elimination, augmented matrix is : \n\n") ;
 	for(i=0; i<n; i++){
  	for(j=0; j<2*n; j++)
            printf("  %4.2f",matrix[i][j]) ;
  	printf("\n");
 	}
 	printf("\n\n\n The inverse of the entered non-singular matrix is : \n\n");
 	for(i=0; i<n; i++){
  	for(j=n; j<2*n; j++)
            printf("  %.5f",matrix[i][j]);
  	printf("\n");
 	}
 }
