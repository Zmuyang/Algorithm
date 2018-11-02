#include <stdio.h>

int Cal(int n,int p);

int main(){
	int n,p;
	scanf("%d%d",&n,&p);
	printf("%d",Cal(n,p));
	return 0;
} 
int Cal(int n,int p){
	if(n<p) return 0;
	return n/p + Cal(n/p,p);
}
