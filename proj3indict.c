#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inDict ( char*, char*);

int inDict(char *dictionary, char *word ){
  FILE *fp;
  char str[60];
  int before=0, after =0, len;

  fp = fopen("words.txt" , "r");
   if(fp == NULL) {
      perror("Error opening file");
      return -1;
   }
    while( fgets (str, 60, fp)!=NULL ) {
    
      before++;

      len = strlen(str);
      str[len-1] = '\0'; //remove newline character from fgets

      if(strcmp(str, word)==0){
        break;
      }
      after++;
    }
    fclose(fp);

   if(after==before){
     puts("word not found");
     return 0;
   }else{         //the loop was broken before the int after was incremented
     puts("found!");
   }
  return 1;
}

int main(){
  char *dictionary;
  char toCheck[60];
  int findRes;

  dictionary= "words.txt";

  puts("What do you wanna spellcheck?");
  scanf("%s", toCheck);

  findRes= inDict(dictionary, toCheck);
  
  return 0; 
} 