#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *interleave(char first[], char second[]){
	char *result = malloc(sizeof(char) * (strlen(first) + strlen(second)));
	printf("size %lu", sizeof(char) * (strlen(first) + strlen(second)));
	int maxLength = 0;
	if(strlen(first) > strlen(second)){
		maxLength = strlen(first);
	}else{
		maxLength = strlen(second);
	}
	result = "hi";
	// int i;
	// for(i = 0; i < maxLength; i++){
	// 	if(first[i]){

	// 	}
	// }
	return result;
}

int main (){
	char *returned = interleave("heei", "eepie");
	printf("hope: %s", returned);
}