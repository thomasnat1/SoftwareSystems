#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	char line[80];
	FILE *out = fopen(argv[1], "w");
	printf("%s\n", argv[1]);
	while(scanf("%79s[^\n]\n", line) == 1){
		printf("%s\n", line);
		fprintf(out, "%s\n", line);
	}
	fclose(out);
}
