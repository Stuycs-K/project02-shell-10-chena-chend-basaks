#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void parseArgs(char *line, char **args);
void executeCommand(char *command, int input, int output);
char *redirectStdout(char *command, int output);
char *redirectStdin(char *command, int input);
void pipe(char *a, char *b);
#endif
