#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t t;
    srand((unsigned)time(&t));//seed from timer.h
    int r=0,count_xor_0=0,count_xor_1=0,count_xor_0div=0,count_xor_1div=0;
    //P(xi = 0/xi−1 = 0)
    // bin ==> binary string containing the seed;
    char bin[127];// here indexing starts from 0 that is bin[0]_to_bin[126] contains the seed;
    int n=1000000,prev=0;
    r = rand()%2;
    bin[0] = r+'0';
    r = rand()%2;
    prev = r;
    if(r) count_xor_1div++;
    else  count_xor_0div++;
    for(int i=1;i<127;i++){
        r = rand()%2;
        if(prev==0){
            if(r==0) count_xor_0++;
            if(r==1) count_xor_1++;
            count_xor_0div++;
        }
        else{
            count_xor_1div++;
        }
        prev = r;
        if(r)  bin[i] = '1';
        else   bin[i] = '0';
    }
    printf("%s\n",bin);
    
    prev = bin[126]-'0';
    int current;//current position
    for(int i=127;i<n;i++){
        int bit = bin[(i-127)%(127)] - '0';
        int current = prev^bit;
        if(prev==0){
            if(current==0) count_xor_0++;
            if(current==1) count_xor_1++;
            count_xor_0div++;
        }
        else{
            count_xor_1div++;
        }
        prev = current;
        bin[(i-127)%127] = current + '0';
    }
    
    printf("====================================\n");
    printf("USING XORG:\nP(xi = 0/xi-1 = 0):\t%.9Lf\n",((long double)count_xor_0)/count_xor_0div);
    printf("P(xi = 0/xi-1 = 1):\t%.9Lf\n",((long double)count_xor_1)/count_xor_1div);
    printf("====================================\n\n");
    int count_rand_0=0,count_rand_1=0,count_rand_1div=0,count_rand_0div=0;
    r = rand()%2;
    prev = r;
    if(r) count_rand_1div++;
    else  count_rand_0div++;
    //NOW LET US CALCULATE THE PROBABILITY USING rand()%2;
    for(int i=0;i<n;i++){
        r = rand()%2;
        if(prev==0){
            if(r==0)  count_rand_0++;
            if(r==1)  count_rand_1++;
            count_rand_0div++;
        }
        else{
            count_rand_1div++;
        }
        prev = r;
    }
    printf("====================================\n");
    printf("USING rand():\nP(xi = 0/xi-1 = 0):\t%.9Lf\n",((long double)count_rand_0)/count_rand_0div);
    printf("P(xi = 0/xi-1 = 1):\t%.9Lf\n",((long double)count_rand_1)/count_rand_1div);
    printf("====================================\n");
    return 0;
}