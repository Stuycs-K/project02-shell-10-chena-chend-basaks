#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
#include <signal.h>
#include <string.h>
#include <unistd.h>
int main () {
	int running = 0;
	while(running == 0){
		char* inputBuffer = (char*) malloc(256);
		char* pathBuff = (char*) malloc(256);
		getcwd(pathBuff, 255);
		if (isatty(STDIN_FILENO)) {
		    printf("%s$ ", pathBuff);
		}
		fflush(stdout);
	    char* commandBuffer;
        if(fgets(inputBuffer, 255, stdin) == NULL || strcmp(inputBuffer, "exit")  == 0) {
    		printf("\n");
            exit(0);
        }
        while((commandBuffer = strsep(&inputBuffer, ";"))){
            parseCommand(commandBuffer);
        }
        fflush(stdout);
	}
	fflush(stdout);
	exit(0);
}


