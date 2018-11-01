#include <stdio.h>

int BinarySearch(int A[],int L,int R,int x);

int main(){
	int A[10];
	for(int i=0;i<10;i++) scanf("%d",&A[i]);
	int x;
	scanf("%d",&x);
	printf("%d",BinarySearch(A,0,9,x));
	return 0;
}
int BinarySearch(int A[],int L,int R,int x){
	int mid;
	while(L<=R){
		mid = L+(R-L)/2;
		if(x==A[mid]) return mid;
		else if(A[mid]<x) L=mid+1;
		else R=mid-1;
	}
	return -1;
}
