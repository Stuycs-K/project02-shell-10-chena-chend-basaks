#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include "functions.h"

void readCommand(char *command) {
    //piping:
//    int p[2];
//    pipe(p);
    //pass fd[1] into output parameter of first command
    //pass fd[0] into input parameter of second command
    char *command2 = strsep(&command, "|");
    printf("%s[]\n%s[]\n", command, command2);
}

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
    parseArgs(strdup(command), args);
    pid_t p = fork();
    if (p == 0) {
        dup2(input, STDIN_FILENO);
        dup2(output, STDOUT_FILENO);
        execvp(args[0], args);
        exit(0);
    }
    int status;
    wait(&status);
}

char *redirectStdout(char *command, int output) {
    return NULL;
}
char *redirectStdin(char *command, int input) {
    return NULL;
}
void pipe_(char *a, char *b);