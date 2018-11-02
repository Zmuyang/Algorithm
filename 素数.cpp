#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool Prime(int a);

int main(){
	int n;
	scanf("%d",&n);
	if(Prime(n)) printf("YES!");
	else printf("NO!");
	return 0;
}

bool Prime(int a){
	if(a<=1) return false;
	int sqr=(int)sqrt(1.0*a);
	for(int i=2;i<=sqr;i++){
		if(a%i==0) return false; 
	}
	return true;
}
