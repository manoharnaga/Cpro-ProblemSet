#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef long long ll;

int main(int argc,char *argv[]){
    FILE *fptr1 = fopen(argv[1],"r+");
    FILE *fptr2 = fopen(argv[2],"r+");
    FILE *fptrw = fopen(argv[3],"w+");
    char word1[20];
    char word2[20];
    char temp[20];
    //i points to elements in file1 ==> word1
    //j points to elements in file2 ==> word2
    int f1=0,f2=0;
    fscanf(fptr1,"%s",word1);
    fscanf(fptr2,"%s",word2);
    while(!(f1 || f2))
    if(strcmp(word1,word2)>0){
        fprintf(fptrw,"%s\n",word2);
        if(fscanf(fptr2,"%s",word2)!=EOF) continue;
        else                               {f2=1;break;}
    }
    else if(strcmp(word1,word2)<0){
        fprintf(fptrw,"%s\n",word1);
        if(fscanf(fptr1,"%s",word1)!=EOF)   continue;
        else                                {f1=1;break;}
    }
    else if(strcmp(word1,word2)==0){
        fprintf(fptrw,"%s\n",word1);
        fprintf(fptrw,"%s\n",word2);
        if(fscanf(fptr1,"%s",word1)!=EOF)  continue;
        else                                {f1=1;break;}
        if(fscanf(fptr2,"%s",word2)!=EOF)  continue;
        else                                {f2=1;break;}
    }
    if(f1){
        fprintf(fptrw,"%s\n",word2);
        while(fscanf(fptr2,"%s",word2)!=EOF){
            fprintf(fptrw,"%s\n",word2);
        }
    }
    if(f2){
        fprintf(fptrw,"%s\n",word1);
        while(fscanf(fptr1,"%s",word1)!=EOF){
            fprintf(fptrw,"%s\n",word1);
        }
    }
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptrw);
    return 0;
}