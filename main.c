#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main () {
	char* inputBuffer = (char*) malloc(256);
	fgets(inputBuffer, 255, stdin);
    char* commandBuffer = inputBuffer;
	while((commandBuffer = strsep(&inputBuffer, ";"))){
		//function to execute a command
	}
}
