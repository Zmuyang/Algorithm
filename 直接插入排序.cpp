#include <stdio.h>

int num[10];

void InsertSort();

int main(){
	for(int i=0;i<10;i++) scanf("%d",&num[i]);
	InsertSort();
	for(int i=0;i<10;i++) printf("%d ",num[i]);
	return 0;
}

void InsertSort(){
	for(int i=1;i<10;i++){
		int temp=num[i];
		int j=i;
		while(j>0 && temp < num[j-1]){
			num[j]=num[j-1];
			j--;
		}
		num[j]=temp;
	}
}
