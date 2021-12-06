#include <stdio.h>

int main()
{
	//initialization
	int i;
    int len;

    //Input the length of the sequence
    printf("Input the length of the sequence that you want to see:");
    scanf("%d",&len);

    //Initialize and print the first two element of the sequence
	int a[len];  
	printf("Display the Fibonacci sequence\n");
	a[0]=0;
	a[1]=1;
	printf("%d ",a[0]);  
	printf("%d ",a[1]);  
	
	//print the sequence one by one
	for(i=2;i<len;i++){ 
		a[i] = a[i-1] + a[i-2];  
		printf("%d ",a[i]);  
	} 
	printf("\n");
	
	return 0;
}
//start showing negative number
//the 50th element of the Fabonacci sequence is nearly 126 million, way bigger than the maximum of the "int" type variable which is 2147483647