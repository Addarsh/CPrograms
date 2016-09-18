#ifndef NODE_H
#define NODE_H 
	typedef struct Node{
		int key;
		struct Node* next;
	} Node;

	Node* BuildOneTwoThree();
	int Length(Node*);
	void Push(Node**,Node*);
#endif
