//Count the number of occurences
//of an integer in a linked list
#include <stdio.h>
#include <stdlib.h>
#include "../LinkedList.h"

int count(Node* head,int elem){
	int mycount = 0;
	Node* curr = head;
	while(curr){
		if(curr->key == elem) mycount++;
		curr = curr->next;
	}
	return mycount;
}

int main(int argc, char* argv[]){
	Node* head = BuildOneTwoThree();
	printf("%d\n",count(head,3));
	return 0;
}
