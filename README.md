[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Tfg6waJb)
# Systems Project2 - MyShell
Team Members: David Chen, Souvik Basak
Creative Team Name: Microsoft Tech Support

Our Shell Features:
1. Display of the path of current directory
2. Commands such as cd
3. Redirection of the output of a command to a file(command > file)
4. Redirection of the input of a file to a command(command < file)
5. Redirection of the output of a command to the input of another(command | command)

Our function headers:
1. char *trim(char *str);
2. void parseArgs(char *line, char **arg_ary);
3. void parseCommand(char *command);
4. void executeCommand(char *command, int input, int output);
5. int redirectStdin(char *command, int input);
6. int redirectStdout(char *command, int output);

