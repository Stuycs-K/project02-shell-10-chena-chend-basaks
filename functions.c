#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "functions.h"

char *trim(char *str) {
    if (*str == ' ') {
        str++;
    }
    int end = strlen(str)-1;
    if (str[end] == ' ') {
        str[end] = '\0';
    }
    return str;
}

//helper function for using execvp
void parseArgs(char *line, char **args) {
    int i = 0;
    while (line) {
        args[i++] = strsep(&line, " ");
    }
    args[i] = NULL;
}

void parseCommand(char *command) {
    int end = strlen(command)-1;
    if (command[end] == '\n') {
        command[end] = '\0';
    }
    char *command2 = command;
    command = strsep(&command2, "|");

    if (command2) {
        int pipeIO[2];
        pipe(pipeIO);
        executeCommand(trim(command), STDIN_FILENO, pipeIO[1]);
        executeCommand(trim(command2), pipeIO[0], STDOUT_FILENO);
        close(pipeIO[0]);
        close(pipeIO[1]);
    } else {
        executeCommand(trim(command), STDIN_FILENO, STDOUT_FILENO);
    }
    wait(NULL);
}

//executing a single command
void executeCommand(char *command, int input, int output) {
    char *args[100];
    char *commandCopy = strdup(command);
    parseArgs(trim(commandCopy), args);
    if (!strcmp(args[0], "cd")) {
        chdir(args[1]);
        executeCommand("ls", STDIN_FILENO, STDOUT_FILENO);
        return;
    }
    if (!strcmp(args[0], "exit")) {
        exit(0);
    }
    if (fork() == 0) {
        input = redirectStdin(command, input);
        output = redirectStdout(command, output);
        parseArgs(trim(command), args);
        dup2(input, STDIN_FILENO);
        dup2(output, STDOUT_FILENO);
        execvp(args[0], args);
        exit(0);
    }
}

int redirectStdin(char *command, int input) {
    char *inputFile = command;
    //removes everything after the < in command
    command = strsep(&inputFile, "<");
    if (inputFile) {
        return open(trim(inputFile), O_RDONLY, 0);
    }
    return input;
}

int redirectStdout(char *command, int output) {
    char *outputFile = command;
    //removes everything after the > in command
    command = strsep(&outputFile, ">");
    if (outputFile) {
        return open(trim(outputFile), O_CREAT | O_WRONLY | O_TRUNC, 0640);
    }
    return output;
}