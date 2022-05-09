// Abhishek Dave
// 5/3/22

#ifndef _STACK_H_
#define _STACK_H_

struct Node{
	char symbol;
	struct Node* next; 
};

struct Stack{
	struct Node* head; 
};


struct Stack* newStack(); 

int isEmpty(struct Stack* S);

void push(char symbol, struct Stack* S);

void pop(struct Stack* S);

int top(struct Stack* S);

#endif 
