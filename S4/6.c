#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef long long ll;

int main(int argc,char *argv[]){
    ll count=0;
    ll a[123]={0};
    char ch;
    FILE *fptrw;
    FILE *fptr;
    for(int i=2;i<argc;i++){
        fptr = fopen(argv[i],"r+");
        while(fscanf(fptr,"%c",&ch)!=EOF){
            a[((int)ch)]++;
        }
        fclose(fptr);
    }
    fptrw = fopen(argv[1],"w+");
    // (i>=48 && i<=57) || (i>=65 && i<=91) || (i>=97 && i<=122)
    for(int i=0;i<123;i++){
        if((i>=48 && i<=57) || (i>=65 && i<=90) || (i>=97 && i<=122)){
            fprintf(fptrw,"%c:%lld\n",(char)i,a[i]);
        }
    }
    fclose(fptrw);
    return 0;
}