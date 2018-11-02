#include <stdio.h>
#include <math.h>
typedef long long LL;

typedef struct Fraction{
	LL up;
	LL down;
}Fraction;

int Gcd(int a,int b);
Fraction Add(Fraction r1,Fraction r2);
Fraction Minu(Fraction r1,Fraction r2);
Fraction Multi(Fraction r1,Fraction r2);
Fraction Divide(Fraction r1,Fraction r2);
void ShowResult(Fraction r);

int main(){
	Fraction r1,r2;
	scanf("%d%d",&r1.up,&r1.down);
	scanf("%d%d",&r2.up,&r2.down);
	ShowResult(Add(r1,r2));
	printf("\n");
	ShowResult(Minu(r1,r2));
	printf("\n");
	ShowResult(Multi(r1,r2));
	printf("\n");
	ShowResult(Divide(r1,r2));
	printf("\n");
	return 0;
}

Fraction Reduction(Fraction r){
	if(r.down<0){
		r.up*=(-1);
		r.down*=(-1);
	}
	if(r.up==0) r.down=1;
	else{
		int d = Gcd(abs(r.up),abs(r.down));
		r.up /= d;
		r.down /= d;
	}
	return r;
}

Fraction Add(Fraction r1,Fraction r2){
	Fraction r;
	r.up = r1.up * r2.down + r2.up * r1.down;
	r.down = r1.down * r2.down;
	return Reduction(r);
}

Fraction Minu(Fraction r1,Fraction r2){
	Fraction r;
	r.up = r1.up*r2.down - r2.up*r1.down;
	r.down = r1.down * r2.down;
	return r; 
}

Fraction Multi(Fraction r1,Fraction r2){
	Fraction r;
	r.up = r1.up * r2.up;
	r.down = r1.down * r2.down;
	return Reduction(r);
}

Fraction Divide(Fraction r1,Fraction r2){
	Fraction r;
	r.up= r1.up * r2.down;
	r.down = r1.down * r2.up;
	return Reduction(r);
} 

void ShowResult(Fraction r){
	r=Reduction(r);
	if(r.down==1) printf("%lld",r.up);
	else if(abs(r.up) > r.down) printf("%d %d/%d",r.up/r.down,r.down);
	else printf("%d/%d",r.up,r.down);
}
int Gcd(int a,int b){
	return !b ? a : Gcd(b,a%b);
}
