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

    int num;
    srand(time(NULL));
    num = rand() % k;

    a[b[num]/3][b[num]-3*(b[num]/3)] = 2;
}

void computerMoveIntelligentlyFirst(int *a[])
{
    //middle is most important 
    if(a[1][1]==1){
        switch(getRandomNum(4)){
            case 1:
                a[0][0] = 2;
                break;
            case 2:
                a[0][2] = 2;
                break;
            case 3:
                a[2][0] = 2;
                break;
            case 4:
                a[2][2] = 2;
                break;
        }
    }else{
        a[1][1] = 2;
    }
}

int analyse(int a[3][3],int *p)
{
    int i,j;//i for horizontal line, j for vertical row
    int k=0;//X-->+1 O-->-1
    int judge = -1;

    //search the horizontal line
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(a[i][j]==1){
                k++;
            }else if(a[i][j]==2){
                k--;
            }
        }
        if(k==2||k==-2){
            judge = 0;
            *p = i;
            break;
        }
        k = 0;
    }

    //search the vertical row
    if(k!=2&&k!=-2){
        for(j=0;j<3;j++){
            for(i=0;i<3;i++){
                if(a[i][j]==1){
                    k++;
                }else if(a[i][j]==2){
                    k--;
                }
            }
            if(k==2||k==-2){
                *p = j;
                judge = 1;
                break;
            }
            k = 0;
        }
    }

    //search the cross line
    if(k!=2&&k!=-2){
        for(i=0;i<3;i++){
            if(a[i][i]==1){
                k++;
            }else if(a[i][i]==2){
                k--;
            }
        }
        if(k==2){
            judge = 2;
        }else if(k==-2){
            judge = 2;
        }
    }



    if(k!=2&&k!=-2){
        k = 0;
        for(i=0;i<3;i++){
            if(a[i][2-i]==1){
                k++;
            }else if(a[i][2-i]==2){
                k--;
            }
        }
        if(k==2){
            judge = 3;
        }else if(k==-2){
            judge = 3;
        }
    }

    return judge;

}

void computerMoveIntelligently(int *a[],int array[3][3])
{
    //by analysing,choose a place to move
    int m = -1;
    int i,j;
    int k = 0;
    int p;
    int len = 0;
    int num;

    analyse(array,&m);

    if(analyse(array,&m)==0){
        for(i=0;i<3;i++){
            if(a[m][i]==0){
                a[m][i] = 2;
                break;
            }
        }
    }else if(analyse(array,&m)==1){
        for(i=0;i<3;i++){
            if(a[i][m]==0){
                a[i][m] = 2;
                break;
            }
        }
    }else if(analyse(array,&m)==2){
        for(i=0;i<3;i++){
            if(a[i][i]==0){
                a[i][i] = 2;
                break;
            }
        }
    }else if(analyse(array,&m)==3){
        for(i=0;i<3;i++){
            if(a[i][2-i]==0){
                a[i][2-i] = 2;
                break;
            }
        }
    }else{
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
        a[blk[p]/3][blk[p]%3] = 2 ;
    }
}

int main()
{
    //initielization
    int num;
    int Brd[3][3] = {0,0,0,0,0,0,0,0,0};
    int *a[3];
    int i;
    int counter = 0;

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
            if(counter==0){
                computerMoveIntelligentlyFirst(a);
            }else{
                computerMoveIntelligently(a,Brd);
            }
            counter++;
            getchar();
            printBoard(Brd);
        }else{
            break;
        }
    }while(haveWinner(Brd)==0&&scanBoard(Brd)==0);

    //judge the ending
    if(haveWinner(Brd)==1){
        printf("You Win\n");
    }else if(haveWinner(Brd)==2){
        printf("You Lose\n");
    }else{
        printf("End in a draw\n");
    }

    return 0;
}