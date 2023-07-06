#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char *argv[]){
    int i=0,n=1000000;
    time_t t;
    int count1=0,count2=0,count3=0,count4=0,count5=0,count6=0;
    int dice_val=0;
    srand((unsigned) time(&t));//Initialising the seed with value from timer.h's t
    
    for(i=1;i<=n;i++){
        dice_val = (rand()%6) + 1;
        //fprintf(fptr,"%d ",dice_val);
        switch (dice_val)
        {
        case 1:
            count1++;
            break;
        case 2:
            count2++;
            break;
        case 3:
            count3++;
            break;
        case 4:
            count4++;
            break;
        case 5:
            count5++;
            break;
        case 6:
            count6++;
            break;      
        default:
            break;
        }
    }
    printf("FREQUENCY OF 1:\t%d\n",count1);
    printf("FREQUENCY OF 2:\t%d\n",count2);
    printf("FREQUENCY OF 3:\t%d\n",count3);
    printf("FREQUENCY OF 4:\t%d\n",count4);
    printf("FREQUENCY OF 5:\t%d\n",count5);
    printf("FREQUENCY OF 6:\t%d\n",count6);
    return 0;
}