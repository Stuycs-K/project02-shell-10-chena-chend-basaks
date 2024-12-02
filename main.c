#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main () {



	char* commandBuffer = malloc(256);
	char* currentSegment = malloc(256);
	fgets(commandBuffer, 255, stdin);
	while(currentSegment = strsep(&commandBuffer, " ")){
		printf("%s \n", currentSegment);

	}

}
