#include<stdio.h>

//the declaration of functions' head files
void drawRoom(int x,int y,int x1,int y1);//the main process of drawing a room
void target(int x,int x1);//to show where the player locates
void boundary(int x);//to print the boundary of the room by '+' and '|'
void inside(int x);//to print the inside of the room 



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
    int i;
    int j;
    
    x += 2;
    y += 2;
    x1 += 2;
    y1 += 2;
    /*the reason why each parameters need to plus 2 is that parameters 'x,y,x1,y1' are the length and coordinate
    without considering the boundary of the room*/
    /*e.g.:+----+   for a room like that,the parameter sent in the function should be'x=4,y=3,x1=1,y1=1',
           |....|   but the actual length of the room is x+2,the actual width of the room is y+2.
           |.@..|   so for convenience,I just add each parameters 2
           |....|
           +----+  */

    for(j=1;j<=y;j++){
        if( j==1 || j==y){
            boundary(x);//when drawing the line of boundary use the function 'boundary'
        }else if(j==y1){
            target(x,x1);//when drawing the line where the player locates use the function 'target'
        }else{
            inside(x);//when drawing the inside use the function 'inside'
        }
    }
}



void target(int x,int x1)
{
    int i;
    for(i=1;i<=x;i++){
        if(i==x1){
            printf("@");
        }else if(i==1){
            printf("|");
        }else if(i==x){
            printf("|\n");
        }else{
            printf(".");
        }
    }
}
void boundary(int x)
{
    int i;
    for(i=1;i<=x;i++){
        if(i==1){
            printf("+");
        }else if(i==x){
            printf("+\n");
        }else{
            printf("-");
        }
    }
}


void inside(int x)
{
    int i;
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
