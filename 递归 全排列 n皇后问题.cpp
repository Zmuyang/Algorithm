#include <stdio.h>
#include <stdbool.h>
#include <math.h>

const int MAX=11;
int P[MAX],cnt=0,n;
bool HashTable[MAX]={false};
void GenerateP(int index);
int main(){
	scanf("%d",&n);
	GenerateP(1);
	printf("%d",cnt);
	return 0;
}
/*
void GenerateP(int index){
	if(index == n+1){
		bool flag=true;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if( abs( i-j) == abs( P[i] - P[j] )) flag=false;
			}
		}
		if(flag) cnt++;
		return;
	}
	for(int x=1;x<=n;x++){
		if(!HashTable[x]){
			P[index]=x;
			HashTable[x]=true;
			GenerateP(index+1);
			HashTable[x]=false;
		}
	}
}   */

//回溯法
void GenerateP(int index){
	if(index==n+1){
		cnt++;
		return;
	}
	for(int x=1;x<=n;x++){  // x是行 
		if(!HashTable[x]){
			bool flag=true;
			for(int pre=1;pre<index;pre++){ //pre是列 
				//第index列的皇后行号为 x, 第per列的皇后的行号为 P[pre]； 
				if(abs(index-pre)==abs(x-P[pre])){  //列差 == 行差 
					flag=false;  //对角线冲突 
					break;
				}
			}
			if(flag){
				P[index]=x;
				HashTable[x]=true;
				GenerateP(index+1);
				HashTable[x]=false;
			}
		}
	}
} 
