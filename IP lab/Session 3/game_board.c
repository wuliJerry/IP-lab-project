#include<stdio.h>
#define YES 1
#define NO 0

void printBoard(int a[3][3])
{
    int i;//line,horizontal
    int j;//row,vertical
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(a[i][j]){
                printf("X ");
            }else if(a[i][j]==0){
                printf(". ");
            }
        }
        printf("\n");
    }
}

void cleanScreen(void)
{
    int i;
    for(i=0;i<5;i++){
        printf("\n\n\n\n");
    }
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
    i = 2 * (num / 3) + 1;

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
        return NO;
    }else{
        return YES;
    }
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


    do{
        getchar();

        cleanScreen();

        //input the move*/
        printf("Please choose a place to put your chess");
        scanf("%d",&num);

        //easy(num,a);
        //mobile(num,a);
        computerKeypad(num,a);

        printBoard(Brd);


    }while(scanBoard(Brd) == 0);

    printf("game over\n");

    return 0;
}