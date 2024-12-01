#include<stdio.h>
#include<stdlib.h>
void decreaseOdd(int *arr,int size){
for(int i=0;i<size;i++){
	if(arr[i]%2!=0){
		arr[i]=arr[i]-1;
		}
}
}
int main(){
int size = 5;
int *arr=(int *)malloc(size*sizeof(int));
	printf("Enter the array values:\n");
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	decreaseOdd(arr,size);
	printf("New array is:\n");
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	free(arr);

	
	
	return 0;
}