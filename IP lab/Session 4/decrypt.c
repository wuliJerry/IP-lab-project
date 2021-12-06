#include<stdio.h>
#include<string.h>
#include<math.h>

int getOriginNum(int count)//count ranging from 0-19
{
    int file[20] = {15643, 6913, 6916, 23040, 2377, 6985, 6408, 3657, 5638, 3084, 2119, 15910, 23079, 13629, 23101, 10300, 10557, 23073, 13092, 23369};
    return (file[count]^31337);
}

void decToBin(int num,char* bin)//Decimal system to binary system
{
    char org[16];

    //get the character in reverse order
    for(int i=0;i<16;i++){
        if(num%2==1){
            org[i] = '1';
        }else{
            org[i] = '0';
        }
        num /= 2;
    }

    //change the reverse order into right order
    for(int j=0;j<16;j++){
        *(bin+j) = org[15-j];
    }
}

void seParate(char bin_0[],char* bin_1,char* bin_2)//separate a 16 bit character into two 8 bit characters
{
    for(int i=0;i<8;i++){
        *(bin_1+i) = bin_0[i];
    }
    for(int j=0;j<8;j++){
        *(bin_2+j) = bin_0[8+j];
    }
}

int binToDec(char bin[])//Binary system to decimal system
{
    int dec = 0;
    for(int i=0;i<8;i++){
        if(bin[i]=='0'){
            continue;
        }
        dec += pow(2,7-i); 
    }

    return dec;
}

void printTheLetter(int num)//print out the letters
{
    printf("%c",num);
}

int main()
{
    //initialization of arraies and variables
    int num_1;
    int num_2;
    char bin_0[17];    
    bin_0[16] = '\0';
    char bin_1[9];
    bin_1[8] = '\0';
    char bin_2[9];
    bin_2[8] = '\0';


    //Print out the letters one by one
    for(int count=0;count<20;count++){
        decToBin(getOriginNum(count),bin_0);
        
        seParate(bin_0,bin_1,bin_2);
        
        num_1 = binToDec(bin_1);
        num_2 = binToDec(bin_2);
        
        printTheLetter(num_1);
        printTheLetter(num_2);
    }

    return 0;
}