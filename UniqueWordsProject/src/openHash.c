//Abhishek Dave
//4/25/2022

#include "openHash.h" 
#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 

// Creates and initializes new Linked List struct 
struct LinkedList* newLinkedList(){
	struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	list->head = NULL;
	list->tail = NULL;
	return list; 
} 

// Creates and initializes new open hash struct, takes input of hash table size  
struct OpenHash* newOpenHash(int size){
	struct OpenHash* openHash = (struct OpenHash*)malloc(sizeof(struct OpenHash));
	openHash->table = malloc(sizeof(struct LinkedList) * size); 	
	openHash->size = size;
	openHash->totalCount = 0;
	openHash->uniqueCount = 0;
	for(int i=0; i<size; i++){
		openHash->table[i] = newLinkedList(); 	
	}

	return openHash; 
}

// Hashing function used to get a hash index, takes inputs of word and hash table size  
int hash(char* string, int N){
	int total = 0;
	int i = 0;
	char c; 	
	while(string[i] != '\0'){
		c = string[i]; 
		total = total + (int) c;
		total = total * 101;
		total = total % N;
		i = i+1; 	
	} 
	return total;  
}

// Function to determine if a specific word is already in the hash table, takes inputs of word and openHash struct 
int member(char* string, struct OpenHash* H){
	int index = hash(string, H->size); 
	struct Node *current;
	current = malloc(sizeof(current)); 	
	struct LinkedList *list; 

	list = H->table[index];
	current = list->head;

	while(current!=NULL){ 
		if(strcmp(current->value,string)==0){ 
			return 1; 
		}
		current=current->next; 
	} 
	return 0; 
}

// Inserts word into end of linked list within hash table, takes arguments of word and OpenHash struct 
void insert(char* string, struct OpenHash* H){
	int index = hash(string, H->size);
	struct Node *newNode;
	struct LinkedList *list; 	

	newNode = malloc(sizeof(newNode));
	newNode->value = string; 
	newNode->next = NULL; 	

	list = H->table[index];
	
	if(list->head==NULL){
		list->head = newNode;
		list->tail = newNode; 
	}
	else{
		list->tail->next = newNode;
		list->tail = newNode; 
	} 
}

// Prints out stats of hash table, takes input of OpenHash struct  
void hashStats(struct OpenHash* H){
	int count; 
	double total=0; 	
	double avgLength; 	
	struct LinkedList *list;
	
	struct Node *current;	
	current = malloc(sizeof(current)); 
	
	printf("Total Words: %d\n", H->totalCount);
	printf("Unique Words: %d\n", H->uniqueCount);
	printf("Hash Size: %d\n", H->size);

	for(int i=0; i<H->size; i++){
		count = 0;	
		list = H->table[i];
		current = list->head;
		if(current != NULL){	
			while(current!=NULL){
				count = count + 1; 
				current = current->next;
			}	
		}
		printf("Row %d contains %d values.\n", i, count);
		total = total + count; 
	}
	
	avgLength = total/H->size; 	
	printf("Average Length: %.2f\n", avgLength); 
} 
