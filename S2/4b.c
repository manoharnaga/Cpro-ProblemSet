#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;
int main(int argc,char *argv[]){
    
    long double mean=0,var_sum=0,a=0,var=0;
    FILE *fptr1 = fopen(argv[1],"r+");
    FILE *fptr2 = fopen(argv[2],"r+");
    fscanf(fptr2,"%Lf",&mean);
    fclose(fptr2);
    
    ll count=0;//Number of Elements in the FILE
    FILE *fptrw = fopen(argv[3],"w+");
    while(fscanf(fptr1,"%Lf",&a) != EOF){
        count++;
        var_sum += ((a-mean)*(a-mean));
    }
    fprintf(fptrw,"%.9Lf",(var_sum/(count)));
    fclose(fptrw);
    return 0;
}
