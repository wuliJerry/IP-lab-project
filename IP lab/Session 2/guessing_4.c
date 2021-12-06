#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()

{
    ////initialization 
    int i = 0;//the number of guesses
    int best_score = 0;
    int num;//the random number
    int count;//the counter of each round
    int N;//the value which player guesses

    do{
        srand((int)time(NULL));   
        count = 0;//reset the counter
        num = ( rand() % 32 + 8 ) * 4;//generate a random number eligible

        do{
            printf("Please input a number divisible between 32 and 156 ( including both of it ) :");
            scanf("%d",&N); 

            if( N > num ){
                printf("Too Big!\n");
            }else if( N < num ){
                printf("Too Small!\n");
            }else{
                printf("Bingo!\n");
            }
            count++;
        } while ( N != num );

        i++;//the times of guesses add 1
        if( i == 1 ){
            best_score = count;
        }else{
            if( best_score > count ){
                best_score = count;
            }
        }
        //update the best score if needed
        getchar();
    } while ( i < 4 );

    getchar();

    printf("Your best score is:%d\n",best_score);//out put the final score

    return 0;
}
