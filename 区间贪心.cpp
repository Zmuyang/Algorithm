#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX=110;

typedef struct Inteval{
	int R,L;
}INV;
INV I[MAX];

int CMP(INV a,INV b);

int main(){
	int n;
	while(scanf("%d",&n),n!=0){
		for(int i=0;i<n;i++) scanf("%d%d",&I[i].L,&I[i].R);
		sort(I,I+n,CMP);
		int ans=1,LL=I[0].L;
		for(int i=1;i<n;i++){
			if(I[i].R<=LL){
				LL=I[i].L; //�������� 
				ans++; 
			}
		}
		printf("%d",ans);
	}
	return 0;
}

int CMP(INV a,INV b){
	if(a.L!=b.L) return a.L>b.L;  //����˵�Ӵ�С���� 
	else return a.R<b.R;     //��˵���ͬ���Ҷ˵��С�������� 
}
