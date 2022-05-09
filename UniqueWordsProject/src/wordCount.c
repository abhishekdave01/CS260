//Abhishek Dave
//4/25/2022

// Sources:
// 1) My code from hw2 and hw3
// 2) Professor Boady's lecture slides on Queues, Linked Lists, and Hash Tables
// 3) Professor Boady himself talked me through some issues and pointed out some bugs I had to fix.
// 4) https://www.tutorialspoint.com/c_standard_library/c_function_isalpha.htm (To find a function that would
// check if a character is an alphabet or not) 

#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <ctype.h> 
#include "openHash.h"

//Function to get the word count of words within a certain file
//Takes 2 inputs, hash table size and filename 
int wordCount(int size, char *file); 

//Main Function
//Takes 2 command line arguments
int main(int argc, char** argv){
	//Check we are given two arguments
	char *file;
	int size;
	int len; 
	if(argc==3){
		size = atoi(argv[1]);
		len = strlen(argv[2]);	
		file = (char *)malloc(len);
		strcat(file, argv[2]); 
	}
	else{
		return 1; 	
	}
 		
	wordCount(size, file); 
	return 0; 
}

// Reads every word of example files and put them in hash table if not already there
// Counts total words, unique words, and average words 
int wordCount(int size, char *file){ 
	FILE *filePtr;
	char *word = malloc(50);
	char *buffer = malloc(50);
	char c; 
	int bufferIndex; 

	struct OpenHash* H = newOpenHash(size); 
	int len; 

	filePtr = fopen(file, "r");

	if(filePtr == NULL){
		printf("\nCannot open or find %s.\n", file); 	
	}
	else{
		while(fscanf(filePtr,"%s", word) != EOF){
			char *buffer = malloc(50); 
			len = strlen(word);
			bufferIndex = 0; 	
			
			for (int i=0; i<len; i++){
				c = word[i];
				if(isalpha(c)){
					buffer[bufferIndex] = tolower(c); 
					bufferIndex = bufferIndex+1; 
				} 
			}
			
			if(buffer[0]!='\0'){ 
				if(member(buffer, H)==0){
					H->uniqueCount += 1; 	
					insert(buffer, H); 
				}
				H->totalCount +=1; 
			}	 
		} 

		fclose(filePtr);
		hashStats(H);
		free(word); 
	}  
}
