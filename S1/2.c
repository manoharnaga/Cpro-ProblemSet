#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
    int n=1000000;
    time_t t;
    srand((unsigned) time(&t));//Initialising the seed with value from timer.h's t
    int count[13]={0};//count[0],count[1] are not taken so total number of numbers = 13-2= 11;
    //highest index=count[12];
    int dice1=0,dice2=0,sum=0;
    
    for(int i=0;i<n;i++){
        dice1 = (rand()%6) + 1;
        dice2 = (rand()%6) + 1;
        sum = dice1 + dice2;
        count[sum]++;
    }
    printf("FREQUENCY OF 2 IS: %d\n",count[2]);
    printf("FREQUENCY OF 3 IS: %d\n",count[3]);
    printf("FREQUENCY OF 4 IS: %d\n",count[4]);
    printf("FREQUENCY OF 5 IS: %d\n",count[5]);
    printf("FREQUENCY OF 6 IS: %d\n",count[6]);
    printf("FREQUENCY OF 7 IS: %d\n",count[7]);
    printf("FREQUENCY OF 8 IS: %d\n",count[8]);
    printf("FREQUENCY OF 9 IS: %d\n",count[9]);
    printf("FREQUENCY OF 10 IS: %d\n",count[10]);
    printf("FREQUENCY OF 11 IS: %d\n",count[11]);
    printf("FREQUENCY OF 12 IS: %d\n",count[12]);
    
    return 0;
}