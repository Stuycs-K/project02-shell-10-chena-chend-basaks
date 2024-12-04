#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
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
    //assume input and output are already opened
    char *args[100];
    parseArgs(command, args);
    //TODO: redirect input and output
    pid_t p = fork();
    if (p == 0) {
        execvp(args[0], args);
    }
    int status;
    pid_t child = wait(&status);
}

char *redirectStdout(char *command, char *output) {
    return NULL;
}
char *redirectStdin(char *command, char *input) {
    return NULL;
}
void pipe_(char *a, char *b);