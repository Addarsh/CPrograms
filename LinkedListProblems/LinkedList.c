//Source file for linked list
#include <stdio.h>
#include "LinkedList.h"
#include <stdlib.h>

//Builds a linked list of 3 nodes
//The key values of the nodes are 1,2 and 3
Node* BuildOneTwoThree(){
	Node* one = (Node*) malloc(sizeof(Node));
	Node* two = (Node*) malloc(sizeof(Node));
	Node* three = (Node*) malloc(sizeof(Node));
	one->key = 1;
	two->key = 2;
	three->key = 3;
	Node* head = NULL;
	Push(&head,three);
	Push(&head,two);
	Push(&head,one);
	return head;
}

//Returns the length of the list
int Length(Node* head){
	Node* curr = head;
	int count = 0;
	while(curr){
		count++;
		curr = curr->next;
	}
	return count;
}

//Insert node at the head
void Push(Node** headref,Node* newNode){	
	if(*headref == NULL){
		*headref = newNode;
		return;
	}
	Node* exhead = *headref;	
	newNode->next = exhead;
	*headref = newNode;
}	
