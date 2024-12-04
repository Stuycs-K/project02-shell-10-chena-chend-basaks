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
    char *args[100];
    parseArgs(command, args);
    pid_t p = fork();
    if (p == 0) {
        dup2(input, STDIN_FILENO);
        dup2(output, STDOUT_FILENO);
        execvp(args[0], args);
    }
    int status;
    wait(&status);
}

char *redirectStdout(char *command, char *output) {
    return NULL;
}
char *redirectStdin(char *command, char *input) {
    return NULL;
}
void pipe_(char *a, char *b);