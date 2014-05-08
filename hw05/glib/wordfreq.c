#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <glib.h>

//splits up string by char and returns array of strings
char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            // assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        // assert(idx == count - 1);
        *(result + idx) = 0;
    }
    return result;
}

int main(int argc, char** argv) {
	//opens file
 	static const char filename[] = "metamorphosis.txt";
	FILE *file = fopen ( filename, "r" );
	char uniqueWords[50000][50];
	int wordCount = 0;

	//init hash
	GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);

	if ( file != NULL ){
		char line [ 128 ];
		//read in line by line
		while ( fgets ( line, sizeof line, file ) != NULL ) {
		    char** words;
		    //get the words
			words = str_split(line, ' ');

		    if (words)
		    {
		        int i;
		        for (i = 0; *(words + i); i++)
		        {
		        	//attempt lookup, create if null
		        	if(g_hash_table_lookup(hash, *(words + i)) != NULL){
		        		g_hash_table_insert(hash, *(words + i), g_hash_table_lookup(hash, *(words + i)) + 1);
		        	}else{
		        		g_hash_table_insert(hash, *(words + i), 1);
		        		strcpy(uniqueWords[wordCount], *(words + i));
		        		wordCount++;
		        	}
		        }
		        printf("\n");
		    }
		}
		fclose ( file );
	}else{
		perror ( filename );
	}

	//go through the words and print them with corresponding count
	int i;
	for(i = wordCount-1; i >= 0; i--){
		printf("the word: '%s' was found: %d times\n", uniqueWords[i], g_hash_table_lookup(hash, uniqueWords[i]));
	}

	return 0;
}
