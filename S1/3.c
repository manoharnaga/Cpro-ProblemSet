#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef long long ll;
int main(){
    double x=0,y=0;//sample point (x,y) RANGE OF x,y ==> [-1,1];
    ll n;//Number of sample points inside square as we are only considering range = [-1,1] for x and y;
    printf("ENTER THE NUMBER OF SAMPLE POINTS: ");
    scanf("%lld",&n);
    int on_circle=0;//NUMBER OF points inside the circle;
    time_t t;
    srand((unsigned) time(&t));//seed
    int r=0;//random number that selects the range of x,y in any of the 4 QUADRANTS;
    FILE *fpp=NULL;
    fpp = fopen("points.dat","w+");
    for(ll i=0;i<n;i++){
        r = rand()%4;
        if(r==0){
            x = ((long double)rand())/RAND_MAX;
            y = ((long double)rand())/RAND_MAX;
            fprintf(fpp,"%.8lf\t %.8lf\n",x,y);
        }
        if(r==1){
            x = ((long double)rand())/RAND_MAX;
            y = -((long double)rand())/RAND_MAX;
            fprintf(fpp,"%.8lf\t %.8lf\n",x,y);
        }
        if(r==2){
            x = -((long double)rand())/RAND_MAX;
            y = ((long double)rand())/RAND_MAX;
            fprintf(fpp,"%.8lf\t %.8lf\n",x,y);
        }
        if(r==3){
            x = -((long double)rand())/RAND_MAX;
            y = -((long double)rand())/RAND_MAX;
            fprintf(fpp,"%.8lf\t %.8lf\n",x,y);
        }
        if((x*x+y*y)<=1) on_circle++;
    }
    fclose(fpp);
    //n=100    q3a1.png
    //n=1000   q3a2.png
    //n=10000  q3a3.png
    //n=100000 q3a4.png
    printf("VALUE OF PI IS: %.9lf\n",4*((double)on_circle/n));//Here n=Number of points inside square;
    return 0;
}