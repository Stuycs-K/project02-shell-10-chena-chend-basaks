#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "functions.h"

int main () {
//	char* inputBuffer = (char*) malloc(256);
//	fgets(inputBuffer, 255, stdin);
//    char* commandBuffer;
//	while((commandBuffer = strsep(&inputBuffer, ";"))){
//        readCommand(commandBuffer);
//	}
	int inputFile = open("input.txt", O_RDONLY, 0);
	int outputFile = open("output.txt", O_WRONLY | O_TRUNC, 0);
	executeCommand("ls -lf", STDIN_FILENO, outputFile);
}


