//Started by: Mark Boady
//Queue Implementation

//Completed by: Abhishek Dave
// 4/18/2022

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>


struct Queue* newQueue(){
	//Implement Me
	struct Queue* Q = (struct Queue*)malloc(sizeof(struct Queue)); 
	Q->head = NULL;
	Q->tail = NULL; 
	return Q;
}


char isEmpty(struct Queue* Q){
	//Implement Me    
	return Q->head == NULL;  
}


void enqueue(int v, struct Queue* Q){
	//Implement Me
	struct Node *newNode;
	newNode = malloc(sizeof(newNode)); 	
	newNode->value = v;
	newNode->next = NULL;
	if(Q->head==NULL){
		Q->head = newNode;
		Q->tail = newNode; 
	}
	else{
		Q->tail->next = newNode;
		Q->tail = newNode; 
	} 
}

int front(struct Queue* Q){
	//Implement Me
	if (Q->head == NULL){
		return -1; 	
	}
	return Q->head->value; 
}


void dequeue(struct Queue* Q){
	//Implement Me
	if(Q->head == NULL){
		return; 	
	}
	struct Node *tmpNode;
	tmpNode = Q->head; 	
	Q->head = Q->head->next; 
	free(tmpNode); 
}


void printQueue(struct Queue* Q){
	if(Q->head==NULL){
		printf("Empty Queue\n");
		return;
	}
	struct Node* n = Q->head;
	printf("Queue Contents: [");
	while(n!=NULL){
		printf("%d",n->value);
		n=n->next;
		if(n!=NULL){
			printf(",");
		}
	}
	printf("]\n");
	return;
}
