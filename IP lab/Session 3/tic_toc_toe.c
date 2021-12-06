#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define YES 1
#define NO 0
//0 ----> . blank
//1 ----> X player
//2 ----> O computer



void printBoard(int a[3][3])
{
    int i;//line,horizontal
    int j;//row,vertical
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(a[i][j]==1){
                printf("X ");
            }else if(a[i][j]==0){
                printf(". ");
            }else{
                printf("O ");
            }
        }
        printf("\n");
    }
}

void cleanScreen(void)
{

    printf("\n\n\n\n");
    
}

void easy(int num,int *a[])
{
    //the corresponding relation between number and the location on the board looks like:
    // 0 1 2
    // 3 4 5
    // 6 7 8
    a[num/3][num%3] = 1;
}

void mobile(int num,int *a[])
{
    //the corresponding relation between number and the location on the board looks like:
    // 1 2 3
    // 4 5 6 
    // 7 8 9
    num--;
    easy(num,a);
}

void computerKeypad(int num,int *a)
{
    //the corresponding relation between number and the location on the board looks like:
    // 7 8 9
    // 4 5 6
    // 1 2 3
    int i;

    num = 9 - num;
    i = 2 * ( num / 3 ) + 1;

    num = 3 * i - num;
    mobile(num,a);
}

int scanBoard(int a[3][3])
{
    int i;
    int j;
    int k = 0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(a[i][j]==0){
                k = 1;
                break;
            }
        }
        if(k){
            break;
        }
    }
    if(k){
        return NO;//have blank
    }else{
        return YES;//have no blank
    }
}

int haveWinner(int a[3][3])
{
    int i,j;//i for horizontal line, j for vertical row
    int k=0;//X-->+1 O-->-1

    //search the horizontal line
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(a[i][j]==1){
                k++;
            }else if(a[i][j]==2){
                k--;
            }
        }
        if(k==3||k==-3){
            break;
        }
        k = 0;
    }

    //search the vertical row
    if(k!=3&&k!=-3){
        for(j=0;j<3;j++){
            for(i=0;i<3;i++){
                if(a[i][j]==1){
                    k++;
                }else if(a[i][j]==2){
                    k--;
                }
            }
            if(k==3||k==-3){
                break;
            }
            k = 0;
        }
    }

    //search the cross line
    if(k!=3&&k!=-3){
        for(i=0;i<3;i++){
            if(a[i][i]==1){
                k++;
            }else if(a[i][i]==2){
                k--;
            }
        }
    }

    if(k!=3&&k!=-3){
        k = 0;
        for(i=0;i<3;i++){
            if(a[i][2-i]==1){
                k++;
            }else if(a[i][2-i]==2){
                k--;
            }
        }
    }

    if(k==3){
        return 1;//player wins
    }else if(k==-3){
        return 2;//computer wins
    }else{
        return 0;//nobody wins
    }
}

void computerMoveRandomly(int *a[])
{
    //generate a 1-d array to store the coordinate of the blank
    int i,j;
    int q = 0;
    int k = 0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(a[i][j]==0){
                k++;
            }
        }
    }

    int b[k];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(a[i][j]==0){
                b[q] = i * 3 + j;
                q++;
            }
        }
    }

    //generate a random coordinate of the blank
    int num;
    srand(time(NULL));
    num = rand() % k;

    a[b[num]/3][b[num]-3*(b[num]/3)] = 2;
}

int main()
{
    //initielization
    int num;
    int Brd[3][3] = {0,0,0,0,0,0,0,0,0};
    int *a[3];
    int i;

    for(i=0;i<3;i++){
        a[i] = Brd[i];
    }

    printBoard(Brd);
    getchar();

    do{
        //player's move
        printf("Your move:\n");
        scanf("%d",&num);
        computerKeypad(num,a);

        printBoard(Brd);
        cleanScreen();
        
        //computer's move
        if(haveWinner(Brd)==0&&scanBoard(Brd)==0){
            computerMoveRandomly(a);
            getchar();
            printBoard(Brd);
        }else{
            break;
        }
    }while(haveWinner(Brd)==0&&scanBoard(Brd)==0);

    if(haveWinner(Brd)==1){
        printf("You Win\n");
    }else if(haveWinner(Brd)==2){
        printf("You Lose\n");
    }else{
        printf("End in a draw\n");
    }

    return 0;
}