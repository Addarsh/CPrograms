//Program to convert
//string to integer in C
#include <stdio.h>
#include <string.h>

int a2i(char mynumber[]){
	char base = '0';
	int num = 0;
	int prod = 1;
	int start = strlen(mynumber) -1;
	int i;
	for(i =0; i < strlen(mynumber); i++){
		int digit = mynumber[start]-base;
		num += prod*digit;
		prod *= 10;
		start--;
	}
	return num;
}


int main(int argc, char* argv[]){
	char mynumber[] = "128";

	int converted = a2i(mynumber);
	printf("Converted number: %d\n",converted);
	return 0;
}
