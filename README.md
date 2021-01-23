# Sorting-Program

This program reads a sequence of words from an input file, sorts the words in alphabetical order and then outputs them on the screen. For simplicitys stake, a word is a sequence of lower case letters. The program contains the following functions.

char **read_words(constchar *input_filename, int *nPtr); - input_filename is a string representing the name of the input file. This function stores the words in an array of strings. The memory for the array of strings and for each string is allocated dynamically. The input file contains a positive integer representing the number of words, on the first line. Then the words follow one per line. The function stores the number of words in the variable pointed to by nPtr. Additionally, the function returns a pointer to the beginning of the array of strings that was dynamically allocated.

void sort_words(char **words, int size); - This function sorts the words in the array of strings in alphabetical order using the sorting algorithm known as “insertion sort”. 

void sort_words(char **words, int size); - This function sorts the words in the array of strings in alphabetical order using the sorting algorithm known as “bubble sort”
