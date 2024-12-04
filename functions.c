#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"

//helper function for using execvp
void parseArgs(char *line, char **args) {
    int i = 0;
    while (line) {
        args[i++] = strsep(&line, " ");
    }
    args[i] = NULL;
}

//executing a single command
void executeCommand(char *command, int input, int output) {
    char *args[100];
    parseArgs(command, args);
    pid_t p = fork();
    if (p == 0) {
      if(input != -1){
        dup2(input, STDIN_FILENO);
      }
      if(output != -1){
        dup2(output, STDOUT_FILENO);
      }
        execvp(args[0], args);
    }
    int status;
    wait(&status);
}
char *redirectStdout(char *command, int output){
  int tempInput  = -1;
  executeCommand(command, tempInput, output);
  return output;
}
char *redirectStdin(char *command, int *input){
  int tempOutput = -1;
  executeCommand(command, input, tempOutput);
  return input;
}
void pipe(char *a, char *b){

}
