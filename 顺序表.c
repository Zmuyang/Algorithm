#include <stdio.h>
#include <stdbool.h>
#define MaxSize 50

struct SqList{
	int data[MaxSize];
	int length;
}L;
int arr[]={5,6,7,8,9,1,2,3,4};

void InitSqList(struct SqList *L);  // 初始化静态顺序表 
bool InsertList(struct SqList *L,int pos,int temp); // 插入操作 
int Dele_Min(struct SqList *L); //删除最小值 
void Reverse(struct SqList *L,int left,int right); // 逆置 
void Dele_x(struct SqList *L,int x); //删除所有值为x的元素 
bool Dele_s_t(struct SqList* L,int s,int);//删除有序顺序表中值为 S-t 之间的元素 
bool Dele_S_T(struct SqList* L,int s,int t);//删除无序顺序表中 s-t 的元素 
int Dele_Same(struct SqList* L);//删除重复的元素值 
bool Merge(struct SqList* A,struct SqList* B,struct SqList* C); //合并两个有序顺序表,包含重复元素
void Reverse_m_n(int arr[],int left,int right);//逆置数组里的两个线性表 
void Search_ExchangeOrInsert(struct SqList* L,int left,int right,int x); //二分查找 
int Majority(struct SqList * L); //2013年计算机联考真题 

int main(){
/*
	Reverse_m_n(arr,0,8);
	Reverse_m_n(arr,0,3);
	Reverse_m_n(arr,4,8);
	for(int i=0;i<9;i++) printf("%d ",arr[i]);
	return 0;
					*/ 
	InitSqList(&L);
/*
	int x;
	x=Majority(&L);
	if(x) printf("%d\n",x);
	else printf("NO\n");
	return 0;
				*/
//	Search_ExchangeOrInsert(&L,0,5,x);
/*	
	InitSqList(&A);
	InitSqList(&B);
	Merge(&A,&B,&C); 
						*/ 
						
//	InsertList(&L,,);
//	Reverse(&L,0,L.length-1);
//	Dele_x(&L,);
//	Dele_S_T(&L,,);
//	Dele_Same(&C);

	printf("%d\n",L.length); 
	for(int i=0;i<L.length;i++) printf("%d ",L.data[i]);
	return 0;
}
void InitSqList(struct SqList *L){
	scanf("%d",&L->length);
	for(int i=0;i<L->length;i++) scanf("%d",&L->data[i]);
}

bool InsertList(struct SqList *L,int pos,int temp){
	if(pos<1||pos>L->length) return false;
	if(L->length>=MaxSize) return false;
	for(int j=L->length;j>=pos;j--){
		L->data[j]=L->data[j-1];
	}
	L->data[pos-1]=temp;
	L->length++;
	return true;
}

int Dele_Min(struct SqList *L){
	int temp=L->data[0];
	int index=0;
	for(int i=1;i<L->length;i++){
		if(temp>L->data[i]){
			temp=L->data[i];
			index=i;
		}
	}
	L->data[index]=L->data[L->length-1];
	L->length--;
	return temp;
}

void Reverse(struct SqList *L,int left,int right){
	for(int i=left,j=right;i<j;i++,j--){
		int temp=L->data[i];
		L->data[i]=L->data[j];
		L->data[j]=temp;
	}
}

void Dele_x(struct SqList *L,int x){
	int index=0;
	for(int i=0;i<L->length;i++){
		if(L->data[i]!=x){
			L->data[index++]=L->data[i];
		}
	}
	L->length=index;
	return 0;
}

bool Dele_s_t(struct SqList* L,int s,int t){
	if( s>=t || L->length==0) return false;
	int i=0,j=0;
	for(;i<L->length && L->data[i]<s;i++);
	if(i>=L->length) return false;
	for(j=i;j<L->length && L->data[j]<=t;j++);
	for(;j<L->length;j++,i++){
		L->data[i]=L->data[j];
	}
	L->length=i;
	return true;
}

bool Dele_S_T(struct SqList* L,int s,int t){
	if(s>=t || L->length==0) return false;
	int k=0;
	for(int i=0;i<L->length;i++){
		if(L->data[i]>=s && L->data[i]<=t){
			k++;
		}else L->data[i-k]=L->data[i];
	}
	L->length-=k;
	return true;
}

int Dele_Same(struct SqList* L){
	if(L->length==0) return 0;
	int index=0;
	for(int j=1;j<L->length;j++){
		if(L->data[index]!=L->data[j]) L->data[++index] = L->data[j];
	}
	L->length=index+1;
	return 0;
}

bool Merge(struct SqList* A,struct SqList* B,struct SqList* C){
	int i=0,j=0,index=0;
	if(A->length+B->length>MaxSize) return false;
	while(i<A->length && j<B->length){
		if(A->data[i]<=B->data[j]){
			C->data[index++]=A->data[i++];
		}else{
			C->data[index++]=B->data[j++];
		}
	}
	while(i<A->length){
		C->data[index++]=A->data[i++];
	}
	while(j<B->length){
		C->data[index++]=B->data[j++];
	}
	C->length=index;
	return true;
} 

void Reverse_m_n(int arr[],int left,int right){
	for(int i=left,j=right;i<j;i++,j--){
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
}

void Search_ExchangeOrInsert(struct SqList* L,int left,int right,int x){
	int i=0,j=right,mid=0;
	while(i<=j){
		mid=(i+j)/2;
		if(L->data[mid]==x) break;
		if(L->data[mid]>x) j=mid-1;
		else i=mid+1;
	}
	if(L->data[mid]==x && mid!=right){
		int temp=L->data[mid];
		L->data[mid]=L->data[mid+1];
		L->data[mid+1]=temp;
	}
	if(i>j){
		for(i=right;i>j;i--) L->data[i+1]=L->data[i];
		L->data[i+1]=x;
		L->length+=1;
	}
}

int Majority(struct SqList* L){
	int y;
	y=L->data[0];
	int cnt=1;
	for(int i=1;i<L->length;i++){
		if(y==L->data[i]) cnt++;
		else {
			if(cnt) cnt--;
			else{
				cnt=1;
				y=L->data[i];
			}
		}
	}
	if(cnt>0){
		cnt=0;
		for(int i=0;i<L->length;i++){
			if(y==L->data[i]) cnt++;
		}
	}
	if(cnt<L->length/2) return y=0;
	else return y;
}
