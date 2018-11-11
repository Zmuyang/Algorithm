/*
	n件物品，每件物品重量为 w[i],价值为 c[i] ,现在需要选出若干件物品放入一个容量为 v
的背包中，在不超重的情况下，让背包中的物品的价值和最大 
*/

#include <cstdio>
const int MAX=110;
int n,v,maxValue=0;
int w[MAX],c[MAX];

void DFS(int index,int sumW,int sumC){
	if(index==n){
		if(sumW<v && sumC>maxValue) maxValue=sumC;
		return ;
	}
	DFS(index+1,sumW,sumC);
	DFS(index+1,sumW+w[index],sumC+c[index]);
}

int main(){
	scanf("%d%d",&n,&v);
	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	DFS(0,0,0);
	printf("%d\n",maxValue);
	return 0;
}
