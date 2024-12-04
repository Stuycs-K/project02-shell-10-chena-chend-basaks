#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void readCommand(char *command);
void parseArgs(char *line, char **arg_ary);
void executeCommand(char *command, int input, int output);
char *redirectStdout(char *command, int output);
char *redirectStdin(char *command, int input);
void pipe_(char *a, char *b);
#endif