//A program is C to write a ring buffer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 2
struct RingBuffer;
bool isFull(struct RingBuffer* buff);
bool isEmpty(struct RingBuffer* buff);

struct RingBuffer{
	int arr[BUFFER_SIZE];
	int head;
	int tail;
	int numElements;
};

void add(struct RingBuffer* buff,int elem){
	if(isFull(buff)) return;
	buff->arr[buff->tail] = elem;	
	buff->tail += 1 % BUFFER_SIZE;
	buff->numElements++;
}

int removeElem(struct RingBuffer* buff){
	if(isEmpty(buff)) return 0;
	int removethis = buff->arr[buff->head];
	buff->head += 1 % BUFFER_SIZE;
	buff->numElements--;
	return removethis;
}

bool isFull(struct RingBuffer* buff){
	return buff->numElements == BUFFER_SIZE;
}

bool isEmpty(struct RingBuffer* buff){
	return buff->numElements == 0;
}


int main(int argc,char* argv[]){
	struct RingBuffer mybuffer;	
	mybuffer.numElements = 0;
	add(&mybuffer,5);
	
	printf("%d\n",isFull(&mybuffer));
	add(&mybuffer,10);
	printf("%d\n",isFull(&mybuffer));
	return 0;
}
