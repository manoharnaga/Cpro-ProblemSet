#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;
int main(int argc,char *argv[]){
    ll in_range=0,total_num=0;
    long double mean=0,sum=0,a=0;
    FILE *fptr1 = fopen(argv[1],"r+");
    FILE *fptr2 = fopen(argv[2],"r+");
    fscanf(fptr2,"%Lf",&mean);
    fclose(fptr2);
    while(fscanf(fptr1,"%Lf",&a) != EOF){
        if((a>=(0.8*mean)) && (a<=(1.2*mean))){
            in_range++;
        }
        total_num++;
    }
    fclose(fptr1);
    FILE  *fptr3 = fopen(argv[3],"w+");
    //fprintf(fptr2,"%lld",count);
    fprintf(fptr3,"%.9Lf\n",(((long double)in_range)/total_num)*100);
    fclose(fptr3);
    return 0;
}