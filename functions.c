#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"

void executeCommand(char *command){
  char* firstcommand = malloc(256);
  char* secondcommand = malloc(256);
  index = 0;
  while(index < strlen(command)){

    if(command[])
    index ++;

  }

}
char *redirectStdout(char *command, char *output){
  char** commandArr = malloc(256);
  char* token = malloc(256);
  int index = 0;
  while(token = strsep(&command, " ")){
    commandArr[index] = token;
    printf("%s \n", commandArr[index]);
  }
}
char *redirectStdin(char *command, char *input){

}
void pipe(char *a, char *b){

}
