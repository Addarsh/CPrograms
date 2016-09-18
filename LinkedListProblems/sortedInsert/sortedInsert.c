//Function for performing sorted
//insert in a linked list
#include <stdio.h>
#include <stdlib.h>
#include "../LinkedList.h"

void sortedInsert(Node** head,Node* newNode){
	Node* curr = *head;
	while(curr->next != NULL){
		if(curr->next->key >= newNode->key){
			Node* after = curr->next;
			curr->next = newNode;
			newNode->next = after;
			return;
		}		
		curr= curr->next;
	}
	//Append to the end
	curr->next = newNode;
}

int main(int argc,char* argv[]){

	Node* head =BuildOneTwoThree();
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = 6;
	printf("length before adding: %d\n",Length(head));
	sortedInsert(&head,newNode);
	printf("length after adding: %d\n",Length(head));
	Node* okNode = (Node*)malloc(sizeof(Node));
	okNode->key = 5;
	sortedInsert(&head,okNode);
	printf("length after adding: %d\n",Length(head));
	return 0;
}	
