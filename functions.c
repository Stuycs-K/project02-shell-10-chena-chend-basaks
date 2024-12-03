#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

void executeCommand(char *command) {

}

char *redirectStdout(char *command, char *output);
char *redirectStdin(char *command, char *input);
void pipe(char *a, char *b);