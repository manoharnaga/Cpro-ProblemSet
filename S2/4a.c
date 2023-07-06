#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int main(int argc,char *argv[]){
    ll count=0;
    long double mean=0,sum=0,a=0;
    FILE *fptr1 = fopen(argv[1],"r+");
    while(fscanf(fptr1,"%Lf",&a) != EOF){
        sum += a;
        count++;
    }
    fclose(fptr1);
    FILE  *fptr2 = fopen(argv[2],"w+");
    fprintf(fptr2,"%.9Lf\n",(sum/count));
    fclose(fptr2);
    return 0;
}