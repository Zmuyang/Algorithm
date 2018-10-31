#include <stdio.h>
#include <string.h>

const int MAX=100;
char S[MAX][5],temp[5];
int HashTable[ 52*52*52 +10];

int HashFunc(char s[]);

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%s",S[i]);
		int id = HashFunc(S[i]);
		HashTable[id]++;
	}
	for(int i=0;i<M;i++){
		scanf("%s",temp);
		int id= HashFunc(temp);
		printf("%d\n",HashTable[id]);
	}
	return 0;
}

int HashFunc(char s[]){
	int id=0;
	for(int i=0;i<strlen(s);i++){
		if(s[i] >= 'A' && s[i] <= 'Z') id = id *52 + (s[i]-'A');
		else if(s[i] >= 'a' && s[i] <= 'z') id = id *52 + (s[i]-'a') + 26;
	}
	return id;
}
