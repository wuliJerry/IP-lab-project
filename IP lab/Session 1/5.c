#include<stdio.h>
#include<math.h>

int main()

{
	//initialization 
	int x = 1;
	double exp_x;
	
	exp_x = 1 + x + pow(x,2)/2 + pow(x,3)/6 + pow(x,4)/24;
	
	//output
	printf("exp_x=%f\n",exp_x);
	printf("%f\n",exp_x = 1+x+(float)x*x/2+(float)x*x*x/6+(float)x*x*x*x/24);
	
	return 0;
}
