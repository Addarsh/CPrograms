//Algorithm to efficiently
//count number of set bits in
//an integer
#include <stdio.h>

int countSetBits(int number){

	int count = 0;
	unsigned int mask = 1;
	while(number > 0){
		if((number & mask) > 0) count++;
		number >>= 1;
	}
	return count;
}

int main(int argc, char* argv[]){
	int number = 1023;
	printf("Number of set bits: %d\n",countSetBits(number));
	return 0;
}
