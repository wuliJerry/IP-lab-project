#include<stdio.h>

void drawRoom(int x,int y,int x1,int y1);
//the declaration of the function "drawRoom"

int main()

{
    drawRoom(2,2,0,1);
    drawRoom(5,3,1,2);
    drawRoom(14,8,8,5);

    getchar();

    return 0;   
}

void drawRoom(int x,int y,int x1,int y1)
{
    int i;//the counter of x axis
    int j;//the counter of y axis

    x += 2;
    y += 2;

    x1 += 2;
    y1 += 2; 

    for(j=1;j<=y;j++){
        if( j==1 || j==y ){
            for(i=1;i<=x;i++){
                if(i==1){
                    printf("+");
                }else if(i==x){
                    printf("+\n");
                }else{
                    printf("-");
                }
            }
        }else if( j==y1 ){
            for(i=1;i<=x;i++){
                if(i==1){
                    printf("|");
                }else if(i==x){
                    printf("|\n");
                }else if(i==x1){
                    printf("@");
                }else{
                    printf(".");
                }
            }
        }else{
            for(i=1;i<=x;i++){
                if(i==1){
                    printf("|");
                }else if(i==x){
                    printf("|\n");
                }else{
                    printf(".");
                }
            }
        }
    } 
}

