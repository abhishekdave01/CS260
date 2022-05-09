// Abhishek Dave
// 5/3/22

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

// Create new empty stack
struct Stack* newStack(){
	struct Stack* S = (struct Stack*)malloc(sizeof(struct Stack));
	S->head = NULL;
	return S;
}

//Check if the stack is empty 
int isEmpty(struct Stack* S){
	if(S->head == NULL){
		return 0; 	
	}   
	else{
		return 1; 	
	} 
}

//Add a new value to the stack
void push(char symbol, struct Stack* S){
	struct Node *newNode;
	newNode = malloc(sizeof(newNode));
	newNode->symbol = symbol;
	newNode->next = S->head;
	S->head = newNode; 
}

//Pop head of stack
void pop(struct Stack* S){
	if(S->head==NULL){
		return; 	
	}
	struct Node *tempNode;
	tempNode = malloc(sizeof(tempNode));
	tempNode = S->head; 	
	S->head = S->head->next;
	free(tempNode); 
}

int top(struct Stack* S){
	if(S->head == NULL){
		return 0; 	
	}
	return S->head->symbol; 
} 
