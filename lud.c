//LU Decomposition
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	float mat[100][100], low[100][100], U[100][100], B[100], Y[100], X[100];
	float sum = 0;
	int n, i, j, k, p;
	printf("\n\tenter the size of the matrix: ");
	scanf("%d",&n);
		
	printf("\nenter the coefficient matrix: \n\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%f",&mat[i][j]);		
	for(j = 0; j < n; j++)
	{
		for(i = 0; i < n; i++)
		{
		    if(i >= j)
		    {
		        low[i][j] = mat[i][j];
		        for(k = 0; k <= j - 1; k++)
		            low[i][j] -= low[i][k]*U[k][j];
		        if(i == j)
		            U[i][j] = 1;
		    }
		    else
		    {
		       
		        U[i][j] = mat[i][j];
		        for(k = 0; k <= i - 1; k++)
		            U[i][j] -= low[i][k] * U[k][j];
		        U[i][j] /= low[i][i]; 
		    }
		}
	 }
	printf("\nL matrix:");
	for(i = 0; i < n; i++)
	{
		printf("\n\t");
		for(j = 0; j < n; j++)
			printf("%f ",low[i][j]);
	}
		
	printf("\n\n");
	
	printf("\nU matrix:");
	for(i = 0; i < n; i++)
	{
		printf("\n\t");
		for(j = 0; j < n; j++)
			printf("%f ",U[i][j]);
	}
		
	printf("\nenter the constant terms\n");
	for(i = 0; i < n; i++)
		scanf("%f",&B[i]);
		
	for(i = 0; i < n; i++)
    	{
        	Y[i] = B[i];
        	for(j = 0; j < i; j++)//Forword substitution
        	{
            		Y[i] -= low[i][j] * Y[j];
        	}
        	Y[i]/=low[i][i];
    	}
    	printf("\n[Y]:");
    	
    	for(i=0;i<n;i++)
    		printf("\n\t%f ",Y[i]);
    	
    	for(i=n-1;i>=0;i--)//Back Substitution
    	{
        	X[i]=Y[i];
        	for(j=i+1;j<n;j++)
        		X[i]-=U[i][j]*X[j];
        }
    	printf("\n\t So the result will be: \n");
    	
    	for(i=0;i<n;i++)
    		printf("\n\t%f ",X[i]);
    		
    	printf("\n\n");
    			
	return 0;
}
