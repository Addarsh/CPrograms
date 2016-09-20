/*
 * Source file for Linked List.h
 * Includes some elemental operations
 * of linked lists
 * Author: Addarsh Chandrasekar
*/
#include <stdio.h>
#include "LinkedList.h"
#include <stdlib.h>

//Builds a linked list of 3 nodes
//The key values of the nodes are 1,2 and 3
Node* BuildOneTwoThree(){
	Node* head = NULL;
	Push(&head,3);
	Push(&head,2);
	Push(&head,1);
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

//Insert node at the head of the list
void Push(Node** headref,int key){
	Node* newNode = (Node*)malloc(sizeof(Node));	
	newNode->key = key;
	newNode->next = NULL;

	if(*headref == NULL){
		*headref = newNode;
		return;
	}
	Node* exhead = *headref;	
	newNode->next = exhead;
	*headref = newNode;
}	
