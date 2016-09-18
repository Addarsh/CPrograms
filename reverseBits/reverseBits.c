//Reverse the bits of a byte
#include <stdio.h>
#include <stdint.h>

uint8_t reverseBits(uint8_t byte){

	int index = 0;
	uint8_t newbyte = 0;
	uint8_t mask = 0x01;
	int i;
	for(i =0; i <8;i++){
		uint8_t bit = (byte & (mask << i)) >> i;
		newbyte |=  bit << 7-i; 	
	}
	return newbyte;
}

int main(int argc,char* argv[]){
	uint8_t a = 16;
	printf("myval: %u\n",reverseBits(a));
	return 0;
}
