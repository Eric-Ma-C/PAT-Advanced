#include<stdio.h>
//48min
typedef struct node{
	int data,next;
}node; 
node l[100005];
int main(){
	int head,n,K;
	scanf("%d%d%d",&head,&n,&K);
	for(int i=0;i<n;i++){
		int a,v,n;
		scanf("%d %d %d",&a,&v,&n);
		l[a].data=v;l[a].next=n;
	}
	int size=0;
	for(int i=head;i!=-1;i=l[i].next){
		size++;
	}
	int count=size/K;
	int lastr=-1,th=head;
	for(int i=0;i<count;i++){
		int j=th,jj=l[j].next;
		for(int k=0;k<K-1;k++){
			int jjj=l[jj].next;
			l[jj].next=j;
			j=jj;jj=jjj;
		}
		l[th].next=jj;
		if(lastr!=-1)l[lastr].next=j;
		else head=j;
		lastr=th;
		th=jj;
	}
	int t=head;
	for(;l[t].next!=-1;t=l[t].next){
		printf("%05d %d %05d\n",t,l[t].data,l[t].next);
	}
	printf("%05d %d %d\n",t,l[t].data,l[t].next);

	getchar();
	getchar();
	return 0;
}

