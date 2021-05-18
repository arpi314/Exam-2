#include<stdio.h>
#include <stdlib.h>
#include <string.h>

char *freadline(FILE *fp);

int main(){

    FILE *fp = fopen("story.txt", "r");

    if(fp == NULL){
        printf("Error!");
    }else{
        char *pInput;
        while(!feof(fp)){
            pInput = freadline(fp);
            printf("%s\n", pInput);
        }   
    }
    
    return 0;
}

char *freadline(FILE *fp){

    int i;
    int sizefb;

    for(i = 0; !feof(fp); i++){
        getc(fp);
    }

    char *pBuffer = (char*)malloc(sizeof(char)*i);
    pBuffer = fgets(pBuffer, i, fp);
    
    printf("%i", i);

    sizefb = sizeof(char)*i;
    printf("\n%i", sizefb);

    if((sizeof(char)*i) == i){
        printf("\nYES");
    }else{
        printf("\nNO");
    }
    return pBuffer;

}


