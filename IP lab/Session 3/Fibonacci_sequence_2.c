#include <stdio.h>


// Fibonacci iteration function
int Fibo(int n)  
{
    if(n<2){
        return n == 0 ? 0 : 1;  
    }
    return Fibo(n-1) + Fibo(n-2);  /* Call the Fbi function itself */
    /* set that F(n)=a_n, while a_n = a_(n-1) + a_(n-2)
       As n>=2 Fibo(n) = Fibo(n-1) + Fibo(n-2)
       e.g. n=5 Fibo(5) = Fibo(4) + Fibo(3)
                =      Fibo(3) + Fibo(2) + Fibo(2) + Fibo(1)
                =  Fibo(2)+Fibo(1)+2*[Fibo(1)+Fibo(0)]+Fibo(1)
                =   5*Fibo(1) + 2*Fibo(0) = 5                                */
}

int main()
{
    //initialization
    int i;
    int len;

    //Input the length of the sequence
    printf("Input the length of the sequence that you want to see:");
    scanf("%d",&len);

    //print the sequence one by one
    printf("Display the Fibonacci sequence:\n");
	for(i=0;i<len;i++){  
		printf("%d ", Fibo(i));
    }  
    return 0;

}
//start showing negative number
//the 50th element of the Fabonacci sequence is nearly 126 million, way bigger than the maximum of the "int" type variable which is 2147483647

