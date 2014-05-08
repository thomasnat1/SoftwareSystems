/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int read_element(int *array, int index) {
    int x = array[index];
    return x;
}


int main ()
{
    int never_allocated;
    int *free_twice = malloc (sizeof (int));
    int *use_after_free = malloc (sizeof (int));
    int *never_free = malloc (sizeof (int));
    int array1[100];
    int *array2 = malloc (100 * sizeof(int));

    // valgrind does not bounds-check static arrays
    read_element(array1, -1);
    read_element(array1, 100);

    // but it does bounds-check dynamic arrays
    read_element(array2, 2);
    read_element(array2, 3);

    // and it catches use after free
    *use_after_free = 17;
    
    // never_free is definitely lost
    *never_free = 17;

    // but this one doesn't
    
    free(free_twice);
    free(never_free);

    free(use_after_free);
    free(array2);
    return 0;
}
 
