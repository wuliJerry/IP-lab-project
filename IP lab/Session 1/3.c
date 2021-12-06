#include<stdio.h>

int main()

{
	float some_number;
	
	some_number = 0.0001;
	
	printf("The float variable value is %f\n",some_number);
	printf("The float variable value is %3f\n",some_number);
	printf("The float variable value is %.3f\n",some_number);
	printf("The float variable value is %6f",some_number);
	//wait for keypress
	
	return 0;
}
