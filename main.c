#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
#include <signal.h>
#include <string.h>
int main () {
	int running = 0;
	while(running == 0){
		signal(SIGINT, sigs);
		char* inputBuffer = (char*) malloc(256);
		fgets(inputBuffer, 255, stdin);
	  char* commandBuffer;
		if(strcmp(inputBuffer, "exit")  == 0){
			exit(0);
		}
		running = quit(0);
		while((commandBuffer = strsep(&inputBuffer, ";"))){
			//function to execute a command

					parseCommand(commandBuffer);

		}

	}
	exit(0);

}

static void sigs(int signo) {
    if ( signo == SIGINT ){
      quit(1);
    }
}

static int quit(int val){
  static int val1 = 0;
  val1 += val;
  return val1;
}
