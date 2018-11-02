#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const int MAX=100010;
int prime[MAX],pNum=0;
bool p[MAX]={false};

struct Facter{
	int x,cnt;
}Fac[10];

void Finde_Prime();

int main(){
	Finde_Prime();
	int n,num;
	scanf("%d",&n);
	printf("%d = ",n);
	int sqr = (int)sqrt(1.0*n);
	for(int i=0;i< pNum && prime[i] <= sqr ; i++){
		if(n % prime[i] == 0){
			Fac[num].x = prime[i];
			Fac[num].cnt=0;
			while(n%prime[i]==0){
				Fac[num].cnt++;
				n /= prime[i];
			}
			num++;
		}
		if(n==1) break;
	}
	if(n!=1){
		Fac[num].x=n;
		Fac[num++].cnt=1;
	}
	for(int i=0;i<num;i++){
		if(i>0) printf("*");
		printf("%d",Fac[i].x);
		if(Fac[i].cnt>1) printf("^%d",Fac[i].cnt);
	}
	return 0;
}

void Finde_Prime(){
	for(int i=2;i<MAX;i++){
		if(!p[i]){
			prime[pNum++]=i;
			for(int j=i+i;j<MAX;j+=i) p[j]=true;
		}
	}
}
