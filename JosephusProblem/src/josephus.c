//Started By: Mark Boady
//Josephus Puzzle


//Completed By: Abhishek Dave
// 4/18/2002

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

//Main Function
//Takes 2 command line arguments
int main(int argc, char** argv){
	//Check that we are given two
	//arguments
	//Also check that they are both > 0
	if(argc==3){
		int numPeople = atoi(argv[1]);
		int killFactor = atoi(argv[2]);
		if(numPeople <= 0 || killFactor <=0){
			return 1; 
		}
		josephus(numPeople, killFactor); 	
	} 
	else{
		return 1;	
	} 
	//Implement this function
	return 0;
}

//Solve the Josephus Problem

int* josephus(int n, int m){
	//Implement this function
	int *order = malloc(sizeof(int)*n);
	int counter=0;
	int index = 0;
	int tmpNum;
	int finalPos; 
	struct Queue* Q = newQueue(); 
	
	for(int i=0; i<n; i++){
		enqueue(i,Q);  
	}
	
	printf("Order: ["); 

	while(!isEmpty(Q)){
		
		if(Q->head == Q->tail){
			finalPos = front(Q);
			printf("%d]\n", finalPos);
			break; 
		}

		if(counter == m-1){
			printf("%d, ", front(Q)); 
			order[index] = front(Q); 
			dequeue(Q);	
			counter = 0;
			index = index + 1; 
		}
		else{
			tmpNum = front(Q); 	
			dequeue(Q);
			enqueue(tmpNum, Q);
			counter = counter + 1; 
		}
	}

	printf("Josephus will sit in position: %d\n", finalPos); 
	return order; 
}
