//Find the missing numbers
#include <stdio.h>
#include <stdlib.h>

int missingNums(int arr[], int n, int missing[]){	
	int* fullarr = (int*)malloc(sizeof(int)*n);
	int i;
	for(i =0;i <n;i++) fullarr[i]= 0;
	for(i =0;i<n-2;i++){
		fullarr[arr[i]-1] = arr[i];
	}
	int index=0;
	for(i=0;i<n;i++){
		if(fullarr[i] == 0) missing[index++] = i+1;
	}

	free(fullarr);
}

int main(int argc,char* argv[]){
	int arr[] = {1,2,4,6};
	int n = 6;
	int missingarr[2];
	missingNums(arr,n,missingarr);
	int i;
	for(i =0; i < 2;i++){
		printf("%d\n",missingarr[i]);
	}
	return 0;
}
