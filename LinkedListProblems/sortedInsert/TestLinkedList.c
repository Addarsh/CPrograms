//Function for performing sorted
//insert in a linked list
#include <stdio.h>
#include <stdlib.h>
#include "../LinkedList.h"

//Insert a node in a sorted list
void sortedInsert(Node** headref,Node* newNode){
	if(*headref == NULL){
		Push(headref,newNode);
		return;
	}
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

//Sorts a given linked
void insertSort(Node** headref){
	if(*headref == NULL) return;
	//Make new list and delete old one
	Node* newListHead;
  Node* curr = *headref;
	while(*headref){
		int key = Pop(headref);	
		Node* newNode = (Node*) malloc(sizeof(Node));
		newNode->key = key;
		sortedInsert(&newListHead,newNode); //Insert in sorted list
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
	if(*headref == NULL) return;
	Node* temp = *headref;
	*headref = (*headref)->next;
	return temp->key;	
}

int main(int argc,char* argv[]){
	Node* head =BuildOneTwoThree();
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = 0;
	sortedInsert(&head,newNode);
	printf("Popped elem: %d\n",Pop(&head));
	printf("Getting nth: n=%d, val=%d\n",1,getNth(head,1));
	return 0;
}	
