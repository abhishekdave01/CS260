//Abhishek Dave
// 5/3/2022

#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include "stack.h" 

int parentheses(char *string);

int main(int argc, char** argv){
	int len;
	char *string; 
	if(argc==2){
		len = strlen(argv[1]);
		string = (char *)malloc(20);
		strcat(string, argv[1]);
		parentheses(string); 
	} 
}

//Function to determine if parentheses are balanced in string
int parentheses(char* string){
	struct Stack* S = newStack();
	char open = '(';
	char close = ')';  

	for(int i=0; i<strlen(string); i++){	
		if(string[i] == open){ 	
			push(string[i], S); 	
		} 
		else if(string[i] == close){   
			if(S->head !=NULL){
				pop(S); 
			} 	
			else{
				printf("False\n");
				return 1; 
			} 	
		} 
	}	
	if(isEmpty(S) == 0){	
		printf("True\n"); 
		return 0; 
	}
	else{
		printf("False\n");
		return 1; 
	} 
} 
