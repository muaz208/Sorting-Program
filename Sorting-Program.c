#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"




char **read_words(const char *input_filename, int *nPtr){

	
    char **word_list;

    /*write your implementation here*/

    FILE *fpointer=fopen(input_filename,"r"); //open the wordfile for reading

    fscanf(fpointer,"%d",nPtr); //the first int is the number of words, read that into nPtr

    word_list=calloc(*nPtr,sizeof(char*)); //alloate memory for an array of char pointers and we want *nPtr of these pointers (The number of words we have, one pointer for each word)

    int i=0;
    char* temp=NULL;



    for(i=0;i<*nPtr;i++){ //loop to allocate memory for all the words
    	temp=calloc(1,10); //temporarlily allocate memory, this is done so we can determine the length of each word so we know how much memory to allocate for it
    	fscanf(fpointer,"%s",temp); //read the string into the temp
    	word_list[i]=calloc(1,strlen(temp)); //allocate memory for each word (1 at a time), and compute the length of the string (that we are holding in temp) and allocate that many bytes. The pointers in the array of pointers will point to these memories we are allocating
    	strcpy(word_list[i],temp); //now the memory is allocated, copy the word from the temp into the actual pointer that points to the memory we allocated for the words
    	free(temp); //deallocate the memory for the temp
    }


    fclose(fpointer); //close the file



    return word_list;


}

int compare_str(const char *str1,const char *str2){

	/*this is a helper function 
   	/*compare_str alphabetically compares two strings.
    	If str2 is alphabetically smaller than str1 (comes before str1),
    	the function returns a 1, else if str1 is smaller than str2, the
    	function returns a 0.*/

	/*write your implementation here and update the return accordingly*/

	int i=0;
	int flag=0;
	int index=0;

	while(i<strlen(str1) || i<strlen(str2)){ //loop to go through each letter in the strings we are comparing

		if(str1[i]==str2[i]){ //check to see if the first letter (second letter, third letter and so on) are equivilent
			(str1+1); //if they are, move the pointer to point to the next letter (str1 is a pointer pointing to the first element (the first letter))
			(str2+1); //move the pointer to point to the next letter in str2 (str2 is a pointer pointing to the first element (the first letter))
			index++; //increment the index variable because we found a equivilent letter, so we need to keep going until we DONT find a match
		}
		else if(str1[index]<str2[index]){ //once first condition fails, that means the letters are different. Check to see if the first letter in the sceond string is bigger (int value wise) then str1
			flag=0; //if so, set our flag to 0, this will indicate that THESE TWO strings are sorted (i.e in the right order respectivley)
			break; //break out of the loop because we know they are in the right order
		}
		else{
			flag=1; // if the first two conditions fail, we know that first string is not in the right order and so we set our flag to 0
			break; //break out of the loop because we know they are not in the right order
		}

		i++;

	}
        return flag;
    

}

void sort_words(char **words, int size){

	/*INSERTION SORT*/
   


	/* The way insertion sort works is that it essentialy divides up the array into a sorted portion and a unsorted portion starting at the index 1 (so for the very first one, the "sorted" portion only has
	 * one element). It then compares the value we are on to the previous value, if the previous value is bigger, then it moves the previous value into the current values position (the one we are looking at now)
	 * It then compares this current value with any remaining values. If the remaining value(s) are smaller, then it will insert the current value we are looking at in between the one we shifted and the one we
	 * just checked (that we found to be smaller). If it was found to be bigger, that value will shift into the position of the first shifted value and so on and this process continues. At the end the value
	 * we are looking at will be "inserted" into a new position depedning on the comparison with the other numbers. Then this process continues, with the new "sorted" portion getting bigger and bigger each iteration  */

	int i=0;
	int position=0;
	char temp[15]; //a tempory character array to temporary hold a string

	for(i=1;i<=size-1;i++){
		strcpy(temp,words[i]); //for the first string we will look at, store it in the temporary value, so that we can shift other strings without losing this one
		position=i; //note the position for the string we are looking at now


		while(position>0 && compare_str(words[position-1],temp)==1){ //a while loop to iterate while the position does not reach 0 AND that when we compare our string (that we are considering in this itertaion (the one in the temp variable)) with all the strings in a position ahed of it, the function should return 1 (which means not sorted or not in the order it should be in). If it returns 0 that means we found a string for which the one we are considering (temp) should be behind (so well end up "inserting" it)
			//swap(&words[position-1],&words[i]);					// another reason we need this temp variable is so that we are always comparing with THIS string for this iteration. We dont want to shift string and now we are comparing two totally different strings that we arnt suppsoe to
			//words[position]=words[position-1];
			strcpy(words[position],words[position-1]); //copy the string in the previous position into the current position
			position--; //decrement the position so we can compare with remaining strings

		}

		//words[position]=temp;
		strcpy(words[position],temp); //after we exit the while loop, "insert" the string we were considering this whole time into the position (where we found it should go (e.x if we found it should be behind the first string, the while loop will have failed and we will have "inserted" into as the sceind string in the array))

	}
}

void swap(char **str1, char **str2){
 
	/*this is a helper function that swaps two words by swapping addresses*/

	char *temp=*str1; //set a temporary pointer that will point to the first string (by doing *str1, we give it the address of the first string so it will point to it)-

	*str1=*str2; //swap the address that str1 holds to the address str2 holds
	*str2=temp; //temp holds the address of the string str1 pointed to, so give that to str2 to complete the swap


}

void sort2_words(char **words, int size){

	/*BUBBLE SORT*/



	/* The way bubble sort works is by comparing each element one by one. It compares the current element with the adjacent one (the one beside it). If it finds that the current element is larger, it will swap
	 * the two elements and then continue to compare, moving on to the element we just compared with and comparing that with the one adjacent to that one, and so on for all elements. After the first iteration
	 * of going through the array, the largest element will be in the last position in the array (where it should be). This segment of the array is essentially the sorted portion (this will get bigger with more
	 * iterations). It will then repeat this, going through element by element until all elements are sorted. After each iteration, it will stop just before the sorted portion of the array because there is
	 * no need to check that portion as nothing will get swapped (more efficient). Essentially with each iteration, the largest element will bubble up to the highest index in the unsorted half */



	int i=0;
	int n=0;

	for(i=1;i<=size-1;i++){ // this for loop will iterate enough times, until size-1 so that the second last and last element can be compared without going over bound. This loop is essentially the number os passes we need to sort the whole array
		for(n=0;n<=size-i-1;n++){ //this loop iterates size-i-1 times because this stops it from going into the sorted portion of the array because there is no point to compare those strings
			if(compare_str(words[n],words[n+1])==1){ //compare the current string (of the index we're on) with the one adjacent to it (index+1) using the compare function. If it returns 1, that means they need to be swapped
				swap(&words[n],&words[n+1]); //call the swap function to swap the strings (e.x the string that was in index 2 gets moved to index 1 and the string at index 1 gets moved to index 2)
			}
		}
	}

    
}

