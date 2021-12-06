#include<stdio.h>
#include<time.h>//extra include
#include<stdlib.h>
#include<malloc.h>

int getTotalDays(long int *sec)
{
    int dy;
    dy = *sec / ( 3600 * 24 );//every hour has 3600 sec.s ,while a day has 24 hours
    *sec = *sec % ( 3600 * 24 );
    return dy;
}

//a leap-year per 4 years, while 2000 is alse a leap-year
//so that during 1970 to today(2021), there is a leap-year every four years
int getYears(int *days)
{
    int yrs = 0;
    for(yrs=0;*days>=365;yrs++){
        if( (yrs+2)%4 == 0 ){
            *days -= 366;
        }else{
            *days -= 365;
        }
    }

    return yrs;
}

int getMonth(int *days,int years)
{
    int mon = 0;

    if((years+2)%4==0){
        if(*days<=31){
            mon = 1;
        }else if(*days<=60){
            mon = 2;
            *days -= 31;
        }else if(*days<=91){
            mon = 3;
            *days -= 60;
        }else if(*days<=121){
            mon = 4;
            *days -= 91;
        }else if(*days<=152){
            mon = 5;
            *days -= 121;
        }else if(*days<=182){
            mon = 6;
            *days -= 152;
        }else if(*days<=213){
            mon = 7;
            *days -= 182;
        }else if(*days<=244){
            mon = 8;
            *days -= 213;
        }else if(*days<=274){
            mon = 9;
            *days -= 244;
        }else if(*days<=305){
            mon = 10;
            *days -= 274;
        }else if(*days<=335){
            mon = 11;
            *days -= 305;
        }else{
            mon = 12;
            *days -= 335;
        }
    }else{
        if(*days<=31){
            mon = 1;
        }else if(*days<=59){
            mon = 2;
            *days -= 31;
        }else if(*days<=90){
            mon = 3;
            *days -= 59;
        }else if(*days<=120){
            mon = 4;
            *days -= 90;
        }else if(*days<=151){
            mon = 5;
            *days -= 120;
        }else if(*days<=181){
            mon = 6;
            *days -= 151;
        }else if(*days<=212){
            mon = 7;
            *days -= 181;
        }else if(*days<=243){
            mon = 8;
            *days -= 212;
        }else if(*days<=273){
            mon = 9;
            *days -= 243;
        }else if(*days<=304){
            mon = 10;
            *days -= 273;
        }else if(*days<=334){
            mon = 11;
            *days -= 304;
        }else{
            mon = 12;
            *days -= 334;
        }

        return mon;
    }
    //For normal year till the end of January 31 days,February 59 days, March 90 days, April 120 days, May 151 days, June 181 days,
    //July 212 days, August 243 days, September 273 days, October 304 days, November 334 days, December 365 days.
    //For leap-year, January 31 days,February 60 days, March 91 days, April 121 days, May 152 days, June 182 days,
    //July 213 days, August 244 days, September 274 days, October 305 days, November 335 days, December 366 days.
}

char* getMonthName(int month)//change the number of month into character
{
    char *Name;
    Name = (char*)malloc(20);

    switch(month){
        case 1 :
            strcpy(Name,"January");
            break;
        case 2 :
            strcpy(Name,"Febuary");
            break;
        case 3 :
            strcpy(Name,"March");
            break;
        case 4 :
            strcpy(Name,"April");
            break;
        case 5 :
            strcpy(Name,"May");
            break;
        case 6 :
            strcpy(Name,"June");
            break;
        case 7 :
            strcpy(Name,"July");
            break;
        case 8 :
            strcpy(Name,"August");
            break;
        case 9 :
            strcpy(Name,"September");
            break;
        case 10 :
            strcpy(Name,"October");
            break;
        case 11 :
            strcpy(Name,"November");
            break;
        case 12 :
            strcpy(Name,"December");
            break; 
    }

    return Name;
}

int getHours(long int *sec)//return a hour number
{
    int hrs = *sec / 3600;
    *sec %= 3600;

    return hrs;
}

int getMinutes(long int *sec)//return a minute number
{
    int min = *sec / 60;
    *sec %= 60;

    return min;
}

void GMT_BJT(int *day,int *hour)//change the GMT into BJT
{
    if(*hour<16){
        *hour += 8;
    }else{
        *hour = *hour + 8 - 24;
        *day ++;
    }
}

void printTime(int year,int month,int day,int hour,int minute)//print out the time
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Today is %s %d,%d,and now is %02d:%02d(in UTC)\n",getMonthName(month),day+1,year,hour,minute);
    GMT_BJT(&day,&hour);
    printf("Today is %s %d,%d,and now is %02d:%02d(in BJT)\n",getMonthName(month),day+1,year,hour,minute);
    printf("\n\n\n\n\n");
}

int main()
{
    //initialization
    time_t sec;
    int day_0;
    int years;
    int months;
    int hours;
    int mins;

    //get variable value
    sec = time(NULL);
    day_0= getTotalDays(&sec);
    years = getYears(&day_0);
    months = getMonth(&day_0,years);
    hours = getHours(&sec);
    mins = getMinutes(&sec);

    printTime(years,months,day_0,hours,mins);
    
    return 0;
}