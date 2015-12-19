#include<stdio.h>
#define points 5
int main(){
	int i,j;
	float X[points],
	      Y[points],
	      Xin=0.0f,poly=0,temp=1;
	printf("Enter the (x,y) values:\n");
	for(i=0;i<points;++i)
	{
		printf("Enter (X%d,Y%d): ",i,i);
		scanf("%f %f",&X[i],&Y[i]);
		putchar('\n');
	}
	printf("Enter the value to interpolate: ");
	scanf("%f",&Xin);
	for(i=0;i<points;++i)
	{
		temp=1;
		for(j=0;j<points;++j)
		{
			if(i!=j)
			{
				temp=temp*(Xin-X[j]);
				temp=temp/((X[i]-X[j]));
			}
	      	}
	      	temp=temp*Y[i];
	      	poly=poly+temp;
	}
	printf("Interpolated value corresponding %f = %f\n",Xin,poly);
	return 0;
	
}
