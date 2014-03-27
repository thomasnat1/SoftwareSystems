#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int negate(int x){
	int y = (x ^ -1) + 1;
	return y;
}



uint8_t low_bits(uint8_t byte, int n){
	int8_t mask = (byte << n) - 1;
	return byte & mask;
}

char *uppercase(char *s){
	int i;
	for(i = 0; i < strlen(s); i++){
		char aChar = s[i];

	}
	return "hi";
}

int main (int argc, char *argv[]){
	printf("%i\n", low_bits(2, 3));
    printf("%s\n", uppercase("sadf"));
}