#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

typedef struct node{
	int v;
	node *left,*right;
}node;
int m,n;
node* tree;
unordered_set<int> has;
node* newnode(int v){
	node* nd=(node*)malloc(sizeof(node));
	nd->v=v;
	nd->left=nd->right=NULL;
	return nd;
}
void insertv(node* &r,int v){
	if(r==NULL){
		r=newnode(v);
		return;
	}
	if(r->v>v)
		insertv(r->left,v);
	if(r->v<=v)
		insertv(r->right,v);
}
bool findk(int k,node *r){
	if(r==NULL){
		return false;
	}
	if(r->v==k){
		return true;
	}
	if(r->v>k)
		return findk(k,r->left);
	else 
		return findk(k,r->right);
}
node* findLCA(int a,int b){
	node *r=tree;
	while(r!=NULL){
		if(r->v>a&&r->v>b){
			r=r->left;
		}else if(r->v<=a&&r->v<=b){
			if(r->v==a||r->v==b)
				break;
			r=r->right;
		}else{
			break;
		}
	}
	return r;
}
int main(){
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		insertv(tree,t);
		has.insert(t);
	}
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);

		node* ans=findLCA(a,b);
		//bool hasa=findk(a,ans);
		bool hasa=has.find(a)!=has.end()?true:false;
		//bool hasb=findk(b,ans);
		bool hasb=has.find(b)!=has.end()?true:false;

		if(!hasa&&!hasb){
			printf("ERROR: %d and %d are not found.\n",a,b);
		}else if(!hasa){
			printf("ERROR: %d is not found.\n",a);
		}else if(!hasb){
			printf("ERROR: %d is not found.\n",b);
		}else {
			if(ans->v==a)
				printf("%d is an ancestor of %d.\n",a,b);
			else if(ans->v==b)
				printf("%d is an ancestor of %d.\n",b,a);
			else
				printf("LCA of %d and %d is %d.\n",a,b,ans->v);
		}

	}
	getchar();
	getchar();
	return 0;
}

