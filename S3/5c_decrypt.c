#include<stdio.h>
int main(int argc,char* argv[]){

    FILE *fptr1 = fopen(argv[1],"r+");//key_file
    int key[127];
    int i=0;
    char c = fgetc(fptr1);//gets the character in the stream
    while(!feof(fptr1)){//statement breaks only when the file ends NOT like EOF
        key[i++] = c-'0';
        c = getc(fptr1);//gets the next character in the stream
    }
    fclose(fptr1);

    FILE *fptr2 = fopen(argv[2],"r+");//encrypted_file
    FILE *fptr3 = fopen(argv[3],"w+");//output_file
    int prev = key[126];//xi-1
    long long k = 0;
    char ch = fgetc(fptr2);
    int value = 0;
    int mult = 128;//multiple of 2
    while(!feof(fptr2)){
        if(mult==0){
            fprintf(fptr3,"%c",value);
            value = 0;
            mult = 128;
        }
        int x = ch - '0';
        int current = (key[(127+k)%127]^prev);//xi = x(i-1) ^ x(i-127)  <(i-127)%127==i  === (i%127)==i>
        key[(127+k)%127] = current;
        value += (x^current)*(mult);
        prev = current;
        mult = mult/2;//Next LSB to Right
        ch = fgetc(fptr2);//gets the character in the stream
        k++;
    }
    fprintf(fptr3,"%c",value);//Last Character
    fclose(fptr2);
    fclose(fptr3);

    return 0;
}