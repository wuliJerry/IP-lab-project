#include<stdio.h>
#define YES 1
#define NO 0


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
            }else if(a[i][j]==2){
                printf("O ");
            }
        }
        printf("\n");
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
            judge = 3;
        }else if(k==-2){
            judge = 3;
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
            judge = 4;
        }else if(k==-2){
            judge = 4;
        }
    }

    return judge;

}

int main()
{
    int num = -1;
    int Brd[3][3] = {0,0,1,0,1,0,2,0,0};
    int *a[3];
    int i;

    for(i=0;i<3;i++){
        a[i] = Brd[i];
    }
    
    int c[3][3];
    for(i=0;i<3;i++){
        c[i][3] = a[i];
    }
    analyse(Brd,&num);

    printf("%d,%d",analyse(Brd,&num),num);

    return 0;
}
