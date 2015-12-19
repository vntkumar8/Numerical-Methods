#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define e 0.00005
#define f(x,y) (2*x*x)+(2*y)
int main(void)
{
	float x0,y0,x1,y1,h,x,newy1,error,xn;
	printf("Enter the value of x(0):");
	scanf("%f",&x0);
	printf("\nEnter the value of y(0):");
	scanf("%f",&y0);
	printf("\nEnter the value of step(h):");
	scanf("%f",&h);
	printf("\nEnter the x bound");
	scanf("%f",&xn);
	x1=x0+h;
	int i=1,j;
	while(x1<=xn+h)
	{
		y1=y0+(h)*f(x0,y0);
		printf("For x = %f ,the corresponding y i's are\n",x1);
		j=1;
		error=1;
		while(error>e)
		{
			
			newy1=y0+(h/2)*(f(x0,y0)+f(x1,y1));
			error=fabs(newy1-y1);
			printf("y(%d)(%d) = %0.3f\t\t error =%f\n",i,j,newy1,error);
			y1=newy1;
			j++;
		}
		printf("\n\nTherefore y(%d) is %0.3f\n",i,y1);
		x0=x0+h;
		y0=y1;
		x1=x0+h;
		i++;
	}
	printf("Hence the answer is %0.3f\n",y1);
}
		

