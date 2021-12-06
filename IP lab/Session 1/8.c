#include<stdio.h>

//initialize the title file of the functions
float Ohm_law(int V,float R);
float series(int r1,int r2);
float parallel(int r1,int r2);

int main()

{
	//int r1=100, r2=200, r3=300, r4=400, r5=500, r6=600, r7=700;
	int r1=123, r2=234, r3=345, r4=456, r5=567, r6=678, r7=789;
	
	//initialization
	float cur;
	float i1,i2,i3;
	const int V = 12;
	
	//caculate the current of three subcircuits
	i1 = Ohm_law(V,series(r1,r2));
	i2 = Ohm_law(V,parallel(r3,r4));
	i3 = Ohm_law(V,series(r5,parallel(r6,r7)));
	
	//sum
	cur = (i1+i2+i3)*1000;
	
	//output
	printf("the overall current in this circuit is %.1lf mA\n",cur);

	getchar();
	return 0;
}


float Ohm_law(int V,float R)
{
	float I;
	I = 1.0 * V / R;
	
	return I;
}


float series(int r1,int r2)
{
	float R;
	R = 1.0 * (r1 + r2);
	return R;
}


float parallel(int r1,int r2)
{
	float R;
	R = r1 * r2 * 1.0 / ( r1 + r2 );
	return R;
}

