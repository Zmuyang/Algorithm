#include <stdio.h>

int Gcd(int a,int b);

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",Gcd(a,b));
	return 0;
}

int Gcd(int a,int b){
	return !b ? a : Gcd(b,a%b);
}
