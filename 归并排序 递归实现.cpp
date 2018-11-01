#include <stdio.h>

const int MAX=110;

int A[MAX],temp[MAX];

void Merge(int L1,int R1,int L2,int R2);
void MergeSort(int L,int R);

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	MergeSort(0,n-1);
	for(int i=0;i<n;i++) printf("%d ",A[i]);
	return 0;
}

void MergeSort(int L,int R){
	if(L<R){
		int mid=L+(R-L)/2;
		MergeSort(L,mid); 
		MergeSort(mid+1,R);
		Merge(L,mid,mid+1,R); 
	}
}

void Merge(int L1,int R1,int L2,int R2){
	int index=0;
	int i=L1;
	int j=L2;
	while(i<=R1 && j<=R2){
		if(A[i]<=A[j]) temp[index++]=A[i++];
		else temp[index++]=A[j++];
	}
	while(i<=R1) temp[index++]=A[i++];
	while(j<=R2) temp[index++]=A[j++];
	for(int i=0;i<index;i++) A[L1+i]=temp[i];
}
