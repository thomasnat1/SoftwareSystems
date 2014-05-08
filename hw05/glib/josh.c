#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int get_count(GHashTable *d, gpointer key){
    if (g_hash_table_contains(d, key))
    {
        return *(int *)g_hash_table_lookup(d, key);
    }
    return 0;
}

// gpointer get_key(GHashTable *d, char **key){
//     if (g_hash_table_contains(d, *key))
//     {
//         return *key;
//     }
//     char *copy = g_strdup(*key);
//     return copy;
// }

// void process_line(GHashTable *d, char *line){
//     char *key;
//     key = strtok(line, " ");
//     int *count = malloc(sizeof(int *));
//     while(key != NULL){
//         printf("%s\n", key);
//         *count = get_count(d, (gpointer)key)+1;
//         g_hash_table_insert(d, get_key(d, &key), count);
//         key = strtok(NULL, " ");
//     }
// }

// void print_pair(gpointer key, gpointer val, gpointer data){
//     printf("word:%s\tfreq:%i\n", (char *)key, *(int *)val);
// }

// void print_words(GHashTable *d){
//     g_hash_table_foreach(d, print_pair, NULL);
// }

int main(int argc, char const *argv[])
{
    // FILE *infile;
    // infile = fopen("test.txt", "r");
    // if (infile == NULL){
    //     printf("%s\n", "404 File not found");
    //     exit(1);
    // }
    GHashTable *word_map = g_hash_table_new(g_str_hash, g_str_equal);
    GIOChannel *channel = g_io_channel_new_file("merchantofvenice.txt","r",NULL);
    gchar *text = NULL;
    gsize len = 0;
    g_io_channel_read_to_end(channel, &text, &len, NULL);
    gchar** words = g_str_tokenize_and_fold(text, "en", NULL);
    int i = -1;
    while (words[++i]){
        int count = get_count(word_map, words[i]) + 1;
        g_hash_table_insert(word_map, &words[i], &count);
    }
    // char line[1000];
    // fgets(line, 1000, infile);
    // printf("%s\n", line);
    // process_line(words, line);
    // while(fgets(line, 1000, infile)){
    //     printf("%s\n", line);
    //     process_line(words, line);
    // }
    // print_words(words);
    return 0;
}