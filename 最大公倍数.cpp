#include <stdio.h>

int Gcd(int a,int b);
int Lcm(int a,int b);

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",Lcm(a,b));
	return 0;
}

int Lcm(int a,int b){
	int d=Gcd(a,b);
	return a / d * b; //·ÀÖ¹Òç³ö 
}

int Gcd(int a,int b){
	return !b ? a : Gcd(b,a%b);
}
