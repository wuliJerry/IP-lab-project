#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define YES 1
#define NO 0
//0 ----> . blank
//1 ----> X player
//2 ----> O computer

int getRandomNum(int range)
{
    int num;
    srand(time(NULL));
    num = rand() % range + 1;

    return num;
}


void fun(int *a[],int array[3][3])
{
    int i,j;
    int k = 0;
    int len;
    int p;
        
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(array[i][j]==0){
                    len++;
                }
            }
        }
        int blk[len];
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(array[i][j]==0){
                    blk[k] = i * 3 + j;
                    k++; 
                }
            }
        }
        p = getRandomNum(len) - 1;
        a[p/3][p%3] = 2 ;

}
int main()
{
    int num = -1;
    int Brd[3][3] = {2,1,0,1,2,0,1,2,1};
    int *a[3];
    int i;

    for(i=0;i<3;i++){
        a[i] = Brd[i];
    }
    
    fun(a,Brd);

    return 0;    

}