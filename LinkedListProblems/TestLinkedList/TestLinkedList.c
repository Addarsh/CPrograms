//Function for performing sorted
//insert in a linked list
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

//Prototype function
void printList(Node* head);

//Insert a node in a sorted list
void sortedInsert(Node** headref,int key){
	if(*headref == NULL){
		Push(headref,key);
		return;
	}

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->next = NULL;

	//Check if it appends in the beginning
	if(newNode->key <= (*headref)->key){
		newNode->next = (*headref);
		*headref = newNode;
		return;
	}
	Node* curr = *headref;
	while(curr->next){
		if(newNode->key <= curr->next->key){
			//Insert
			Node* after = curr->next;
			newNode->next = after;
			curr->next = newNode;
			return;
		}
		curr = curr->next;	
	}
	
	//Append to the end	
	curr->next = newNode;
	newNode->next= NULL;
}

//Get number of elements in the
//linked list
int count(Node* head){
	int mycount = 0;
	while(head){
		mycount++;
		head = head->next;
	}
	return mycount;
}

//Get nth node of linkedlist
int getNth(Node* curr,int n){
	while(curr && n >= 0){
		n--;
		if(n==0) return curr->key;	
		curr = curr->next;
	}
	return -1;
}

//Sorts a given unsorted linked list
void insertSort(Node** headref){
	if(*headref == NULL) return;
	//Make new list and delete old one
	Node* newListHead = NULL;
	while(*headref){
		int key = Pop(headref);	
		sortedInsert(&newListHead,key); //Insert in sorted list
	}
	*headref = newListHead;
}

//Delete a given linked list
void DeleteList(Node** headref){
	Node* curr = *headref;
	while(curr){
		Node* temp = curr;
		curr = curr->next;
		free(temp);
	}	
	*headref = NULL;
}

//Pop the first key of a linked list
int Pop(Node** headref){
	int popkey = -1;
	if(*headref == NULL) return popkey;
	Node* temp = *headref;
	popkey = temp->key;
	*headref = (*headref)->next;
	free(temp);
	return popkey;	
}

//Append linked list b to linked list a
//Make head of linked list b NULL after
void Append(Node** aref, Node** bref){
	Node* curr = *aref;
	while(curr->next){
		curr = curr->next;
	}
	curr->next = *bref;
	*bref = NULL;
}

//InserNth inserts node at Nth index in the list
void insertNth(Node** headref,int key, int n){
	if(*headref == NULL && n != 0) return;
	if(*headref == NULL || n == 0){
		Push(headref,key);
		return;
	}
	if(n > Length(*headref) || n < 0) return;
		
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->key = key;
	Node* curr = *headref;
	while(n > 1 && curr->next){
		curr = curr->next;
		n--;					
	}
	//Append to the end
	Node* temp = curr->next;
	curr->next = newNode;
	newNode->next = temp;
}

//Function to split a list into two sublists
//If odd number, extra node is put in front sublist
void FrontBackSplit(Node* source,Node** frontref,Node** backref){
	int linkLength = Length(source);
	printf("linkLength: %d\n",linkLength);
	int frontLength;
	if(linkLength % 2 == 0) frontLength = linkLength/2;
	else frontLength = linkLength/2 + 1;
	int nodesMoved = 1;
	Push(frontref,source->key);	
	while(nodesMoved < frontLength){
		source = source->next;
		nodesMoved++;
	}
	//Merge to back sublist 
	backref = &(source->next);
	source->next = NULL;
}

//Prints out the linked list 
void printList(Node* head){
	while(head){
		printf("%d --> ",head->key);
		head = head->next;
	}
	printf("NULL\n");
}

int main(int argc,char* argv[]){
	Node* head =BuildOneTwoThree();
	Push(&head,7);	
	Push(&head,4);	
	//printf("Popped elem: %d\n",Pop(&head));
	//printf("Getting nth: n=%d, val=%d\n",1,getNth(head,1));
	//insertSort(&head);
	sortedInsert(&head,6);
	insertSort(&head);
	printList(head);	
	
	Node* subA= NULL;
	Node* subB= NULL;
	//FrontBackSplit(head,&subA,&subB);

	//printList(subA);	
	//printList(subB);	
	
	insertNth(&head,45,6);
	printf("--\n");	
	printList(head);	
	printf("Count = %d\n",count(head));
	return 0;
}
