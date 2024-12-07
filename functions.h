#ifndef FUNCTIONS_H
#define FUNCTIONS_H

static int quit(int val);
char *trim(char *str);
void parseArgs(char *line, char **arg_ary);
void parseCommand(char *command);
void executeCommand(char *command, int input, int output);
int redirectStdin(char *command, int input);
int redirectStdout(char *command, int output);

#endif
