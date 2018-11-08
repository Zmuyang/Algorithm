#include <stdio.h>

int A[10],B[10],C[30];
int Merge(int lenA,int lenB);

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int i=0;i<m;i++) scanf("%d",&B[i]);
	int index=Merge(n,m);
	for(int i=0;i<index;i++) printf("%d ",C[i]);
	return 0;
}

int Merge(int lenA,int lenB){
	int index=0,i=0,j=0;
	while( i<lenA && j<lenB ){
		if(A[i]<B[j]) C[index++] = A[i++];
		else if(A[i]>B[j]) C[index++] = B[j++];
		else {
			C[index++] = A[i++];
			j++;
		}
	}
	while(i<lenA) C[index++]=A[i++];
	while(j<lenB) C[index++]=B[j++];
	return index;
}
