#include <stdio.h>
const int MAX=110;
int A[MAX];

int Partition(int L,int R);
void QuickSort(int L,int R);

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	QuickSort(0,n-1);
	for(int i=0;i<n;i++) printf("%d",A[i]);
	return 0;
}

void QuickSort(int L,int R){
	if(L<R){
		int pos=Partition(L,R);
		QuickSort(L,pos-1);
		QuickSort(pos+1,R);
	}
}

int Partition(int L,int R){
	int temp=A[L];
	while(L<R){
		while(L<R && A[R]>temp) R--;
		A[L]=A[R];
		while(L<R && A[L]<=temp) L++;
		A[R]=A[L];
	}
	A[L]=temp;
	return L;
}
