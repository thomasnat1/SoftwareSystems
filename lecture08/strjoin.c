/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *tracks[] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};

/* Returns a heap-allocated string that contains the strings 
   from the given array, joined up with no spaces between.
*/
char *strjoin(char *array[], int n)
{
	int sizeOfAll = 0;
	int i;
	for(i = 0; i < n; i++){
		sizeOfAll += strlen(array[i]);
	}

	char *result = malloc(sizeOfAll * sizeof(char));
	strcpy(result, array[0]);
	for(i = 1; i < n; i++){
		strcat(result, array[i]);
	}
    return result;
}


int main (int argc, char *argv[])
{
    char *s = strjoin(tracks, 5);
    // char *s = strcat("hi", "bie");
    printf("%s\n", s);
    return 0;
}
