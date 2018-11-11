/*
	n����Ʒ��ÿ����Ʒ����Ϊ w[i],��ֵΪ c[i] ,������Ҫѡ�����ɼ���Ʒ����һ������Ϊ v
�ı����У��ڲ����ص�����£��ñ����е���Ʒ�ļ�ֵ����� 
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
