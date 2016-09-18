//Write a function to convert
//integer to string

#include <stdio.h>
#include <string.h>

void reverse(char* mystr){
	int i;
	for(i=0; i< strlen(mystr)/2;i++){
		char temp = mystr[strlen(mystr)-1-i];
		mystr[strlen(mystr)-1-i] = mystr[i];
		mystr[i] = temp;
	}
}

void i2a(int number, char cstring[]){
	int divisor = 10;
	int i =0;	
	while(number > 0){
		int digit = number % divisor;
		cstring[i++] = digit + '0';
		number = number/divisor;
	}
	cstring[i] = '\0';
	reverse(cstring);
}

int main(int argc, char* argv[]){
	int number = 4;
	char mystr[128];
	i2a(number,mystr);
	printf("String is: %s\n",mystr);
}
