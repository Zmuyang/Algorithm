#include <stdio.h>
#include <stdbool.h>
const int MAX=11;
int P[MAX],n;
bool HashTable[MAX]={false};
void GenerateP(int index);

int main(){
	scanf("%d",&n);
	GenerateP(1);
	return 0;
}
void GenerateP(int index){
	if(index ==  n+1){
		for(int i=1;i<=n;i++) printf("%d",P[i]);
		printf("\n");
		return ;
	}
	for(int x=1;x<=n;x++){
		if(HashTable[x]==false){
			P[index]=x;
			HashTable[x]=true;
			GenerateP(index+1);
			HashTable[x]=false;
		}
	}
}
