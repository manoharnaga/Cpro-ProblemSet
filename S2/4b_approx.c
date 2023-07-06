#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;
int main(int argc,char *argv[]){
    ll count=0;//Number of elements READ from the data;
    long double rmean=0,var_sum=0,a=0,sum=0,var=0,sum_square=0;//rmean == running mean

    FILE *fptr1 = fopen(argv[1],"r+");
    //consider running variance for every 5 elements incremented
    FILE *fptr2 = fopen(argv[2],"w+");
    fscanf(fptr1,"%Lf",&a);
    fprintf(fptr2,"0.000000000\n");//Variance when there is only one number is Zero!
    count = 1;
    sum = a;
    sum_square = a*a;
    while(fscanf(fptr1,"%Lf",&a) != EOF){
        count++;
        sum += a;
        sum_square += a*a;
        rmean = sum/count;((rmean*rmean)*count);
        var_sum = sum_square - ((rmean*rmean)*count);
        var = var_sum/count;
        fprintf(fptr2,"%.9Lf\n",var);
    }
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}
