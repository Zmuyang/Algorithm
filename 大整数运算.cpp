#include <stdio.h>
#include <string.h>

typedef struct bign{
	int d[1000];
	int len;
	bign(){
		memset(d,0,sizeof(d));
		len=0;
	}
}Bign;

Bign Change(char str[]);
int Compare(Bign a,Bign b);
Bign Add(Bign a,Bign b);
void print(Bign a);

int main(){
	char str1[1000];
	char str2[1000];
	scanf("%s%s",str1,str2);
	Bign a=Change(str1);
	Bign b=Change(str2);
	print(Add(a,b));
	return 0;
}
void print(Bign a){
	for(int i=a.len-1;i>=0;i--) printf("%d",a.d[i]);
}

Bign Add(Bign a,Bign b){
	Bign c;
	int carry=0;
	for(int i=0;i<a.len || i<b.len;i++){
		int temp = a.d[i] + b.d[i] +carry;
		c.d[c.len++] = temp % 10;
		carry = temp/10;
	}
	if(carry!=0) c.d[c.len++]=carry;
	return c;
}

int Compare(Bign a,Bign b){
	if(a.len>b.len) return 1;
	else if(a.len < b.len) return -1;
	else{
		for(int i=a.len-1;i>=0;i--){
			if(a.d[i] > b.d[i]) return 1;
			else if(a.d[i]<b.d[i]) return -1;
		}
		return 0;   
	}
}

Bign Change(char str[]){
	Bign a;
	a.len = strlen(str);
	for(int i=0;i<a.len;i++) a.d[i] = str[a.len-i-1] - '0';
	return a;
}
