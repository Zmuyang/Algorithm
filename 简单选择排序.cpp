#include <stdio.h>

int main(){
	int num[10];
	for(int i=0;i<10;i++) scanf("%d",&num[i]);
	for(int i=0;i<10;i++){
		int k=i;
		for(int j=i;j<10;j++){
			if(num[j]<num[k]) k=j;
		}
		int temp = num[k];
		num[k]=num[i];
		num[i]=temp;
	}
	for(int i=0;i<10;i++) printf("%d ",num[i]);
	return 0;
}
