#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
	int data;
	struct NODE* next;
}Node;


void Init_tou(Node *P);  //初始化带头结点单链表 
void Insert(Node *P); // 尾插法 
void Init(Node* P); //初始化不带头结点的单链表 

void Dele_x(Node *P,int x); // 递归删除不带头结点的单链表中值为x的元素
void Dele_tou_x(Node* P,int x);//删除带头结点的单链表中值为 x 的元素 
void ReversePrintf(Node* P); //逆向输出链表 
void Dele_min(Node* P);//删除带头结点单链表中的最小值 
void Invert1(Node* P); // 头插法就地逆置带头结点单链表 
void Invert2(Node* P); // 利用指针就地逆置带头结点单链表 
void Sort_ascending(Node *P);//带头结点单链表元素递增有序 
void Sort_descending(Node* P); // 带头结点单链表元素递减有序 
void Dele_s_t(Node *P,int s,int t); // 删除无序带头结点单链表介于s和t之间的元素 
int Search_same(Node* F1,Node *F2); // 寻找公共结点 
void Dele_ascending(Node *P); // 递增顺序删除头结点 
void DisList10(Node* P,Node *a,Node* b);//分解链表 
void DisList11(Node* P,Node* b);//分解链表,链表有偶数个元素 
void Dele_samevalue(Node *P); //删除相同元素值 
void MergeList(Node *A,Node *B);//合并两个链表 
void Get_Common(Node* L,Node* A,Node* B);//公共元素产生新链表 
void Union(Node* A,Node* B); // 交集 
int Continuous_Subsequence(Node* A,Node* B);//连续子序列 
int Search_K(Node *a,int K); // 倒数第k个元素 

int main(){
	Node* L=(Node*)malloc(sizeof(Node)); // 头结点 
	Node* A=(Node*)malloc(sizeof(Node)); // 头结点 
	Node* B=(Node*)malloc(sizeof(Node)); // 头结点
	Init_tou(L);
	Search_K(L,3);
	return 0;
/*	 
	Init_tou(A);
	Init_tou(B);
	if(Continuous_Subsequence(A,B)==0) printf("B是A的连续子序列");
	else printf("B不是A的连续子序列");
	return 0;   */ 
//	Union(A,B);
//	Get_Common(L,A,B); 
//	MergeList(A,B);
//	Dele_samevalue(p);
//	DisList11(p,B);
//	Dele_ascending(p); 
/*
	p=L2;
	Init_tou(p);
	p=Search_same(L1,L2);
*/	
//	Dele_s_t(p,3,9);
//	Sort_descending(p);
//	Invert2(p); 
/*	
	while(p->next!=NULL) p=p->next;
	Insert(p);
					*/ 
//	Dele_tou_x(p,1);
//	ReversePrintf(p);
//	Dele_min(p);
	
	while(A->next!=NULL){
		A=A->next;
		printf("%d ",A->data);
	} 
	return 0;
}

void Init_tou(Node *P){
	P->next=NULL;
	Node *r=P;
	int x=0;
	int len=0;
	scanf("%d",&len);
	for(int i=0;i<len;i++){
		scanf("%d",&x);
		Node* s=(Node*)malloc(sizeof(Node));
		s->data=x;
		s->next=r->next;
		r->next=s;
		r=s;
	}
}

void Insert(Node *P){
	Node *r=P;
	int x=0;
	int len=0;
	scanf("%d",&len);
	while(len--){
		scanf("%d",&x);
		Node* s=(Node*)malloc(sizeof(Node));
		s->data=x;
		s->next=r->next;
		r->next=s;
		r=s;
	}
}

/*
void Init(Node* P){
	
}

void Dele_x(Node *P,int x){
	Node* q;
	if(P==NULL) return;
	if(P->data==x){
		q=P;
		P=P->next;
		free(q);
		Dele_x(P,x);
	}else Dele_x(P->next,x);
}

*/

void Dele_tou_x(Node* P,int x){
	Node *pre=P,*r=P->next,*q;
	while(r!=NULL){
		if(r->data==x){
			q=r;
			r=r->next;
			pre->next=r;
			free(q);
		}else{
			pre=r;
			r=r->next;
		}
	}
}

void ReversePrintf(Node* P){
	Node* r=P->next;
	if(r!=NULL){
		ReversePrintf(r);
		printf("%d ",r->data);
	}
}

void Dele_min(Node* P){
	Node *pre=P,*p=pre->next;
	Node *minpre=pre,*minp=p;
	while(p!=NULL){
		if(p->data<minp->data){
			minpre=pre;
			minp=p;
		}
		pre=p;
		p=p->next;
	}
	minpre->next=minp->next;
	free(minp);
} 

void Invert1(Node* P){
	Node *p=P->next,*r;
	P->next=NULL;
	while(p!=NULL){
		r=p->next;
		p->next=P->next;
		P->next=p;
		p=r;
	}
}

void Invert2(Node* P){
	Node *pre,*p=P->next,*r=p->next;
	p->next=NULL;
	while(r!=NULL){
		pre=p;
		p=r;
		r=r->next;
		p->next=pre;
	}
	P->next=p;
}

void Sort_ascending(Node* P){
	Node *pre,*p=P->next,*r=p->next;
	p->next=NULL;
	p=r;
	while(p!=NULL){
		r=p->next;
		pre=P;
		while(pre->next!=NULL && pre->next->data < p->data) pre=pre->next;
		p->next=pre->next;
		pre->next=p;
		p=r;
	}
}

void Sort_descending(Node* P){
	Node *pre,*p=P->next,*r=p->next;
	p->next=NULL;
	p=r;
	while(p!=NULL){
		r=p->next;
		pre=P;
		while(pre->next!=NULL && pre->next->data > p->data) pre=pre->next;
		p->next=pre->next;
		pre->next=p;
		p=r;
	}
}

void Dele_s_t(Node *P,int s,int t){
	Node *pre=P,*p=P->next,*q;
	while(p!=NULL){
		if(p->data>s && p->data<t){
			q=p;
			pre->next=p->next;
			p=p->next;
			free(q);
		}else{
			pre->next=p;
			pre=p;
			p=p->next;
		}
	}
}

int Search_same(Node* F1,Node *F2){
	Node *f1=F1,*f2=F2,*SL,*LL;
	int L1=0,L2=0,dist=0;
		L1++;
	while(f1->next!=NULL){
		f1=f1->next;
	}
	while(f2->next!=NULL){
		L2++;
		f2=f2->next;
	}
	LL=L1>L2?F1:F2;
	SL=L1<L2?F1:F2;
	dist=L1>L2?L1-L2:L2-L1;
	while(dist--) LL=LL->next;
	while(LL!=NULL){
		if(LL->data==SL->data) return LL;
		else{
			LL=LL->next;
			SL=SL->next;
		}
	}
	return NULL;
}

void Dele_ascending(Node *P){
	Node *pre,*p,*q;
	while(P->next!=NULL){
		pre=P;
		p=pre->next;
		while(p->next!=NULL){
			if(pre->next->data > p->next->data) pre=p;
			p=p->next;
		}
		printf("%d ",pre->next->data);
		q=pre->next;
		pre->next=q->next;
		free(q);
	}
	free(P);
}

void DisList10(Node* P,Node *a,Node* b){
	Node *p=P->next;
	Node *A=a,*B=b;
	int i=1;
	while(p!=NULL){
		if(i%2!=0){
			A->next=p;
			A=p;
			p=p->next;
			i++;
		}else{
			B->next=p;
			B=p;
			p=p->next;
			i++;			
		}
	}
	A->next=NULL;
	B->next=NULL;
}


void DisList11(Node *P,Node* b){
 	Node *B=b,*r=P,*p=P->next,*q;
 	B->next=NULL;
 	while(p!=NULL){
 		r->next=p;
 		r=p;
 		p=p->next;
 		q=p->next;
 		p->next=B->next;
 		B->next=p;
 		p=q;
	 }
	 r->next=NULL;
}

void Dele_samevalue(Node *P){
	Node *p=P->next,*q;
	if(p==NULL) return;
	while(p->next!=NULL){
		q=p->next;
		if(p->data==q->data){
			p->next=q->next;
			free(q);
		}else p=p->next;
	}
}

void MergeList(Node *A,Node *B){
	Node *r,*pa=A->next,*pb=B->next;
	A->next=NULL;
	while(pa && pb){
		if(pa->data <= pb->data){
			r=pa->next;
			pa->next=A->next;
			A->next=pa;
			pa=r;
		}else{
			r=pb->next;
			pb->next=A->next;
			A->next=pb;
			pb=r;
		}
	}
	if(pa) pb=pa;
	while(pb){
		r=pb->next;
		pb->next=A->next;
		A->next=pb;
		pb=r;
	}
}


void Get_Common(Node* L,Node* A,Node* B){
	Node *r=L,*pa=A->next,*pb=B->next;
	while( pa && pb){
		if(pa->data < pb->data) pa=pa->next;
		else if(pa->data > pb->data) pb=pb->next;
		else{
			r->next=pa;
			r=pa;
			pa=pa->next;
			pb=pb->next;
		}
	}
	r->next=NULL;
}

void Union(Node* A,Node* B){
	Node *pa=A->next,*pb=B->next;
	Node *r=A,*q;
	while(pa && pb){
		if(pa->data==pb->data){
			r->next=pa;
			r=pa;
			pa=pa->next;
			q=pb;
			pb=pb->next;
			free(q);
		}else if(pa->data < pb->data){
			q=pa;
			pa=pa->next;
			free(q);
		}else{
			q=pb;
			pb=pb->next;
			free(q);
		}
	} 
	
	while(pa){
		q=pa;
		pa=pa->next;
		free(q);
	}
	while(pb){
		q=pb;
		pb=pb->next;
		free(q);
	}
	r->next=NULL;
	free(B);
}

int Continuous_Subsequence(Node* a,Node* b){
	Node *pa=a->next,*pb=b->next,*pre=pa;
	while( pa && pb){
		if(pa->data==pb->data){
			pa=pa->next;
			pb=pb->next;
		}else{
			pre=pre->next;
			pa=pre;
			pb=b->next;
		}
	}
	if(pb==NULL) return 0;
	else return 1;
}

int Search_K(Node *a,int K){
	Node *p=a->next,*q=p;
	int cnt=0;
	while(p!=NULL){
		while(cnt<K){
			p=p->next;
			cnt++;
		}
		q=q->next;
		p=p->next;
	}
	if(q!=NULL){
		printf("%d ",q->data);
		return 1;
	}else return 0;
} 


