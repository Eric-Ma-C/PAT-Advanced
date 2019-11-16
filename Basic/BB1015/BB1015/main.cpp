#include<stdio.h>
#include<stdlib.h>
#include<unordered_map>
using namespace std;
struct node{
	int addr;
	int data;
	int next;
};
int head,n=0,k;
unordered_map<int,node> mp;
node *tmp;
node* getAddr(int addr){ 
	auto it=mp.find(addr);
	if(it==mp.end())
		return NULL;
	else
		return &it->second;
}
int main(){
	scanf("%05d %d %d",&head,&n,&k);
	node tmpN;
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&tmpN.addr,&tmpN.data,&tmpN.next);
		mp[tmpN.addr]=tmpN;
	}
	int nn=0;//¿Ó1
	for(node *t=getAddr(head);t!=NULL;t=getAddr(t->next)){
		nn++;
	}
	int count=nn/k;
	int tmpAddr=head;
	node **tmp=(node**)malloc(sizeof(node*)*k);
	node *tmpTail=NULL;
	for(int i=0;i<count;i++){
		for(int j=0;j<k;j++){
			tmp[j]=getAddr(tmpAddr);
			tmpAddr=tmp[j]->next;
		}
		//reverse
		tmp[0]->next=tmp[k-1]->next;
		if(tmpTail==NULL){
			head=tmp[k-1]->addr;
		}else{
			tmpTail->next=tmp[k-1]->addr;
		}
		
		for(int m=1;m<k;m++){
			tmp[m]->next=tmp[m-1]->addr;
		}
		tmpTail=tmp[0];

	}
	if(tmpTail!=NULL)//¿Ó2
		tmpTail->next=tmpAddr;
	
	for(node *t=getAddr(head);t!=NULL;t=getAddr(t->next)){
		if(t->next==-1)
			printf("%05d %d %d\n",t->addr,t->data,t->next);
		else
			printf("%05d %d %05d\n",t->addr,t->data,t->next);
	}
	return 0;
}