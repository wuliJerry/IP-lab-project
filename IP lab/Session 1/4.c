#include<stdio.h>

int main()

{
	//initialization
	int h ,l ,w ,v;
	h = 4;
	l = 5;
	w = 6;
	v = h * l * w;
	
	float weight = v / 1.5;
	
	//output
	printf("The height of the box:%d\n",h);
	printf("The length of the box:%d\n",l);
	printf("The width of the box:%d\n",w);
	printf("The total volume:%d\n",v); 
	printf("Total Weight:%f\n",weight);
	
	return 0;
}
