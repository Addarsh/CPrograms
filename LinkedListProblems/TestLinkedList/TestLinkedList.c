/*
 * Code written in C to implement and test different functions 
 * of a LinkedList.
 * Author: Addarsh Chandrasekar
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h" //Header source includes struct Node definiton
												//and a few elementary operations (Push,Length etc)

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

//Check the array is full already
void checkSize(int n,int* capacity,int* uniquearr){
	if(n == *capacity){
		int* temp = (int*) malloc(sizeof(int)*(*capacity));
		int i;
		for(i =0; i < n;i++) temp[i] = uniquearr[i];
		*capacity = 2* (*capacity);
		uniquearr = (int*)malloc(sizeof(int)*(*capacity));
		for(i =0; i <n;i++)	uniquearr[i] = temp[i];
	}
}


//Add new key element to the array
void addToArr(int n, int key,int* uniquearr,int* capacity){
	checkSize(n,capacity,uniquearr);
	uniquearr[n] = key;
}

//Check if key element is a duplicate
bool checkForDuplicate(int key,int n,int* uniquearr){
	int i;
	for(i =0; i <  n; i++){
		if(uniquearr[i] == key) return true;			
	}
	return false;
}

//Remove duplicates from a list
//Traverse through list only once
//List can be ordered/unordered, no restrictions
void removeDuplicates(Node** headref){
	int capacity = 3;
	int* uniquearr = (int*)malloc(sizeof(int)*capacity);
	int n =0;
	Node* curr = *headref;
	bool isRemoved = false;
	while(curr->next != NULL){
		if(!isRemoved){
			//Add key from curr
			addToArr(n,curr->key,uniquearr,&capacity);
			n++;
		}
		//Check for duplicate from curr->next
		if(checkForDuplicate(curr->next->key,n,uniquearr)){
			//Delete curr->next
			Node* after = curr->next->next;
			Node* remove = curr->next;
			free(remove);
			curr->next = after;
		
			//Dont advance curr, recheck curr again
			isRemoved = true;
			continue;
		}
		isRemoved = false;
		curr = curr->next;
	}
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
	if(*aref == NULL) {
		*aref = *bref;
		*bref = NULL;
		return;
	}
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
	int frontLength;
	if(linkLength % 2 == 0) frontLength = linkLength/2;
	else frontLength = linkLength/2 + 1;
	int nodesMoved = 1;
	Push(frontref,source->key);	
	while(nodesMoved < frontLength){
		source = source->next;
		insertNth(frontref,source->key,nodesMoved);
		nodesMoved++;
	}
	//Add remaining nodes to blist
	Node * curr = source->next;
	int index = 0;
	while(curr){
		insertNth(backref,curr->key,index);
		index++;		
		curr = curr->next;
	}
}

//Take the first node from b and push it
//to the head of a
void moveNode(Node** aref,Node** bref){
	if(*bref == NULL) return;
	Node* bfirst = *bref;
	*bref = (*bref)->next;
	int newkey = bfirst->key; 
	free(bfirst);
	Push(aref,newkey);
}


//Alternating split
//Take odd elements to one list, even to another
void AlternatingSplit(Node* source,Node** aref,Node** bref){
	int n=0;
	while(source != NULL){
		if(n%2 == 0){
			moveNode(aref,&source);
		} else{
			moveNode(bref,&source);
		}
		n++;	
	}
}

//Take two sublists and merge onto a 
// a combined list with alternating elements
Node* ShuffleMerge(Node* a, Node* b){
	Node* merged = NULL;
	int n = 0;
	while(a && b){
		Node* newNode = (Node*)malloc(sizeof(Node));
		if(n%2==0){
			newNode->key = a->key;
			newNode->next = NULL;
			a = a->next;
		}else{
			newNode->key = b->key;
			newNode->next = NULL;
			b = b->next;	
		}
		Append(&merged,&newNode);
		n++;
	}
	while(a){
		insertNth(&merged,a->key,n);
		n++;
		a = a->next;
	}

	while(b){
		insertNth(&merged,b->key,n);
		n++;
		b = b->next;
	}
	return merged;
}

//Merge two lists that are already sorted
Node* SortedMerge(Node** aref, Node** bref){
	Node* merged = NULL;
	while(*aref && *bref){
		if((*aref)->key <= (*bref)->key){
			moveNode(&merged,aref);
		}else{
			moveNode(&merged,bref);
		}
	}
	while(*aref){
		moveNode(&merged,aref);
	}

	while(*bref){
		moveNode(&merged,bref);
	}	

	return merged;
}

void MergeSort(Node** headref){
	if(*headref == NULL) return;
	if(Length(*headref) == 1) return;
	if(Length(*headref) == 2){
		insertSort(headref);
		return;
	}
	Node* left = NULL;
	Node* right = NULL;
	//Split into two sublists	
	FrontBackSplit(*headref,&left,&right);
	MergeSort(&left);
	MergeSort(&right);
	
	DeleteList(headref);
	*headref = SortedMerge(&left,&right);
	insertSort(headref);
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
	insertNth(&head,3,3);
	Push(&head,7);	
	Push(&head,4);	
	
	Push(&head,4);	
	Push(&head,4);	
	//printf("Popped elem: %d\n",Pop(&head));
	//printf("Getting nth: n=%d, val=%d\n",1,getNth(head,1));
	//insertSort(&head);
	//sortedInsert(&head,6);
	//insertSort(&head);
	printList(head);	
	
	removeDuplicates(&head);
	printf("Removing duplicates!\n");
	printList(head);

	Node* subA = NULL;
	Node* subB = NULL;
	
	AlternatingSplit(head,&subA,&subB);
	printf("After alternating and sorting\n");
		
	//After merging
	insertSort(&subA);
	insertSort(&subB);
	printList(subA);
	printList(subB);

	
	printf("Merging sorted lists\n");
	Node* merged = SortedMerge(&subA, &subB);
	printList(merged);
	
	printf("Merging sorting\n");
	MergeSort(&merged);
	printList(merged);
	return 0;
}
