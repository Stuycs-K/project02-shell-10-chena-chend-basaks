#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void parseArgs(char *line, char **arg_ary);
void executeCommand(char *command, FILE *input, FILE *output);
char *redirectStdout(char *command, char *output);
char *redirectStdin(char *command, char *input);
void pipe_(char *a, char *b);
#endif