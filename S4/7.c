#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef long long ll;

int main(int argc,char *argv[]){
    //int n=10000;
    char name[20000][100];
    char word[100];
    FILE *fptrw;
    FILE *fptr;
    int cnt=0;
    fptrw = fopen(argv[1],"w+");
    for(int j=2;j<argc;j++){
        fptr = fopen(argv[j],"r+");
        while(fscanf(fptr,"%s",word)!=EOF){
            strcpy(name[cnt],word);
            cnt++;
        }
        fclose(fptr);
    }
    //printf("%d\n",cnt);
    //BUBBLE SORT IMPLEMENTATION
    char temp[100];
    
    int temp_count=cnt;
    while(1){
        int swap_count=0;
        for(int i=0;i<temp_count;i++){
            if(strcmp(name[i],name[i+1])>0){
                strcpy(temp,name[i]);
                strcpy(name[i],name[i+1]);
                strcpy(name[i+1],temp);
                swap_count++;
            }
        }
        temp_count--;
        if(swap_count<=0) break;
    }
    //BUBBLE SORT IMPLEMENTATION
    int i=1,count=0;
    while(i<=cnt-1){
        strcpy(temp,name[i]);
        while(strcmp(temp,name[i])==0){
            count++;i++;
        }
        fprintf(fptrw,"%s:%d\n",temp,count);
        count = 0;
    }
    fclose(fptrw);
    return 0;
}