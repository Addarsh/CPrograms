//Given an integer n, print the
//first N integers with exactly two bits set
#include <stdio.h>

int countBits(int n){
	int count = 0;
	while(n > 0){
		count += n & 1;
		n >>=1;
	}
	return count;
}

void printFirstN(int n){
	int start = 1;
	int totalNum = 0;
	while(totalNum < n){
		if(countBits(start) == 2){
			totalNum++;
			printf("%d\n",start);
		}
		start++;
	}
}

int main(int argc, char* argv[]){
	int n =5;
	printFirstN(n);

	return 0;
}
