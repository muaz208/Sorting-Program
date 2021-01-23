#include <stdio.h>
#include <stdlib.h>




char **read_words(const char *input_filename, int *nPtr);
void sort_words(char **words, int size);
void sort2_words(char **words, int size);
int compare_str(const char *str1,const char *str2);
void swap(char **str1, char **str2);
