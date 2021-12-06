#include<stdio.h>

int main()

{
	//Initialization all the variable
 	int income;
	float tax;
	float sal;
	
	printf("Enter Gross Income is:￡");
	scanf("%d",&income);
	
	//set different salary level in order to caculate
	if(income<=12500){
		tax = 0;
	}else if(income<=14585){
		tax = ( income - 12500 ) * 0.19; 
	}else if(income<=25158){
		tax = 2085 * 0.19 + ( income - 14585 ) * 0.2;
	}else if(income<=43430){
		tax = 2085 * 0.19 + 10573 * 0.2 + ( income - 25158 ) * 0.21;
	}else if(income<=150000){
		tax = 2085 * 0.19 + 10573 * 0.2 + 18272 * 0.21 + ( income - 43430 ) * 0.41;
	}else{
		tax = 2085 * 0.19 + 10573 * 0.2 + 18272 * 0.21 + 106569 * 0.41 +( income - 150000 ) * 0.46;
	}
	
	sal = income - tax;
	
	//out put the variable
	printf("Your Take-home salary is: ￡%.2f\n",sal);
	printf("The total tax paid is: ￡%.2f\n",tax);
	
	return 0;
}
