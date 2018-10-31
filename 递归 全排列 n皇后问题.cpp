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

//���ݷ�
void GenerateP(int index){
	if(index==n+1){
		cnt++;
		return;
	}
	for(int x=1;x<=n;x++){  // x���� 
		if(!HashTable[x]){
			bool flag=true;
			for(int pre=1;pre<index;pre++){ //pre���� 
				//��index�еĻʺ��к�Ϊ x, ��per�еĻʺ���к�Ϊ P[pre]�� 
				if(abs(index-pre)==abs(x-P[pre])){  //�в� == �в� 
					flag=false;  //�Խ��߳�ͻ 
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
