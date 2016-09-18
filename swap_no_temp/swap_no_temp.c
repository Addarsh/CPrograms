//Swap two numbers without using a temp 
//variable
#include <stdio.h>

void swap(int* a, int* b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int main(int argc, char* argv[]){
	int a = 5;
	int b = 10;
	swap(&a,&b);
	printf("swapped= a: %d, b: %d\n",a,b);

	return 0;
}
