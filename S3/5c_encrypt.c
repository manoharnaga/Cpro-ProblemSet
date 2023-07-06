#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char* argv[]){
    time_t t;
    srand((unsigned) time(&t));//Initialising the seed with value from timer.h's t

    int key[127];//XORG SEED
    FILE *fptr1 = fopen(argv[2],"w+");//key file
    for(int i=0;i<127;i++){
        int num=rand()%2;
        fputc(num+'0',fptr1);
        key[i]=num;
    }
    fclose(fptr1);
    FILE *fptr2 = fopen(argv[1],"r+");//input file
    FILE *fptr3 = fopen(argv[3],"w+");//encrypted file
    int prev = key[126];
    long long k = 0;//k is incremented for every 1 byte
    char c = fgetc(fptr2);
    while(!feof(fptr2)){
        int bit[8];
        int dec = c;
        for(int i=0;i<=7;i++){
            if(dec&1)    bit[7-i] = 1;
            else         bit[7-i] = 0;
            dec = dec>>1;
        }
        for(int j=0;j<8;j++){
            //xi = x(i-1) ^ x(i-127)  <(i-127)%127==i  === (i%127)==i>
            int current = (key[(127+j+(k*8))%127]^prev);
            fprintf(fptr3,"%d",current^bit[j]);
            key[(127+j+(k*8))%127] = current;
            prev = current;
        }
        k++;
        c = fgetc(fptr2);
    }
    
    fclose(fptr2);
    fclose(fptr3);
    return 0;
}