#include <stdio.h>
#include <stdlib.h>
#define MAX_WORD_LENGTH  50


int buscarPalabra(char** words, char* word, int tot){
    for(int i=0; i<tot; i++){
        if (strcmp(words[i], word) == 0){
            return 1;
        }
    }
    return 0;
}

int main(){

    FILE* dictionary = fopen("dictionary.txt","r");

    if(!dictionary){
        printf("error opening the dictionary");
        return 1;
    }

    char** words = (char**) malloc(sizeof(char*));

    if(!words){
        printf("error reserving memory");
        return 1;
    }

    int i=0;
    *words=(char*) malloc(MAX_WORD_LENGTH *sizeof(char));

    while(fgets(*(words+i), MAX_WORD_LENGTH , dictionary) != NULL){
        i++;
        words=realloc(words,(i+1)*sizeof(char*));
        *(words+i)=(char*) malloc(50*sizeof(char));
    }

    free(*(words+i));
    i--;

    if(fclose(dictionary)){
        printf("error closing the dictionary");
        return 1;
    }

    char* word = malloc(MAX_WORD_LENGTH * sizeof(char));

    printf("ingrese una palabra para buscarla en el diccionario:");
    fgets(word, MAX_WORD_LENGTH, stdin);

    if (buscarPalabra(words, word,i)){
        printf("palabra encontrada");
    }else printf("palabra no encontrada");

    return 0;
}


