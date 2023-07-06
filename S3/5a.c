#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t t;
    srand((unsigned)time(&t));//seed from timer.h
    int r=0,count_xor_0=0,count_xor_1=0,count_rand_0=0,count_rand_1=0;
    // bin ==> binary string containing the seed;
    char bin[127];// here indexing starts from 0 that is bin[0]_to_bin[126] contains the seed;
    int n=1000000;
    for(int i=0;i<127;i++){
        r = rand()%2;
        if(r)  bin[i] = '1';
        else   bin[i] = '0';
    }
    printf("%s\n",bin);
    
    int prev = bin[126]-'0';
    for(int i=127;i<n;i++){
        int bit = bin[(i-127)%(127)]-'0';
        int current = prev^bit;
        if(current)  count_xor_1++;
        else         count_xor_0++;
        prev = current;
        bin[(i-127)%127] = current+'0';
    }
    
    printf("%s\n",bin);//the binary string that we get after 1e6-128 operations on seed;
    int no_of_operations = n - 127;
    printf("====================================\n");
    printf("PROBABILITY using XORG for '0': %.9Lf\n",(((long double)count_xor_0)/no_of_operations));
    printf("PROBABILITY using XORG for '1': %.9Lf\n",(((long double)count_xor_1)/no_of_operations));
    printf("====================================\n");
    
    //NOW LET US CALCULATE THE PROBABILITY USING rand()%2;
    for(int i=0;i<n;i++){
        r = rand()%2;
        if(r)  count_rand_1++;
        else   count_rand_0++;
    }
    printf("====================================\n");
    printf("PROBABILITY using rand() for '0': %.9Lf\n",(((long double)count_rand_0)/no_of_operations));
    printf("PROBABILITY using rand() for '1': %.9Lf\n",(((long double)count_rand_1)/no_of_operations));
    printf("====================================\n");
    
    return 0;
}