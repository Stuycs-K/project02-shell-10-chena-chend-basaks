#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void executeCommand(char *command);
char *redirectStdout(char *command, char *output);
char *redirectStdin(char *command, char *input);
void pipe(char *a, char *b);
#endif