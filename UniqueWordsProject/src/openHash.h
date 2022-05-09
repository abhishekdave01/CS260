// Abhishek Dave
// 4/25/2022


#ifndef _OPENHASH_H_
#define _OPENHASH_H_
 
struct Node{
	char* value;
	struct Node* next; 
};

struct LinkedList{
	struct Node* head;
	struct Node* tail; 
}; 

struct OpenHash{
	int size;
	int totalCount;
	int uniqueCount; 	
	struct LinkedList** table;  
};

// Create new LinkedList struct 
struct LinkedList* newLinkedList();

// Create new OpenHash struct 
struct OpenHash* newOpenHash(int size); 

// Hash a String
int hash(char* string, int N);

//Is the item string a member of the hash table H
//Return 1 for Yes and 0 for No
int member(char* string, struct OpenHash* H);

//Insert string into hash table H
void insert(char* string, struct OpenHash* H);

//Hash Stats
void hashStats(struct OpenHash* H);

#endif 
