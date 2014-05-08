/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

void foo(){
	int pie = 4;
	printf("Address of pie is %p\n", &pie);
    foo();
}

int main ()
{
    foo();
    return 0;
}
