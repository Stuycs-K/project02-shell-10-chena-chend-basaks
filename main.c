#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int main () {
	char* inputBuffer = (char*) malloc(256);
	fgets(inputBuffer, 255, stdin);
  char* commandBuffer;
	while((commandBuffer = strsep(&inputBuffer, ";"))){
		//function to execute a command
        executeCommand(commandBuffer);
				
	}
}
