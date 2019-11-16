#include<stdio.h>
typedef struct node{
	int addr,next;
	bool visited;
	char v;
}node; 
node l[100005];
int main(){
	int a1,a2,n;
	scanf("%d %d %d",&a1,&a2,&n);
	int addr,next;char c;
	for(int i=0;i<n;i++){
		scanf("%d %c %d",&addr,&c,&next);
		l[addr].addr=addr;
		l[addr].next=next;
		l[addr].visited=false;
		l[addr].v=c;
	}
	for(int i=a1;i!=-1;i=l[i].next){
		l[i].visited=true;
	}
	int ans=-1;
	for(int i=a2;i!=-1;i=l[i].next){
		if(l[i].visited){
			ans=i;break;
		}
	}

	if(ans!=-1)printf("%05d",ans);
	else printf("-1");
	getchar();
	getchar();
	return 0;
}