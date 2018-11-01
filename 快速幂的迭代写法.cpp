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
	LL ans=1;
	while(b>0){
		if(b&1){
			ans=ans*a%m;
		}
		a=a*a%m;
		b >>= 1;   // b=b/2
	}
	return ans;
} 
