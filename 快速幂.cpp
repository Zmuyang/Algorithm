#include <stdio.h>

typedef long long LL;

LL BinaryPow(LL a,LL b,LL m);

int main(){
	LL a,b,m;
	scanf("%lld%lld%lld",&a,&b,&m);
	a%=m;
	printf("%lld",BinaryPow(a,b,m));
	return 0;
}

LL BinaryPow(LL a,LL b,LL m){
	if(b==0) return 1;
	else if( b&1 ) return a*BinaryPow(a,b-1,m)%m;  //b&1 Ïàµ±ÓÚ b%2==1 
	else{
		LL temp = BinaryPow(a,b/2,m)%m;
		return temp*temp%m;
	}
} 
