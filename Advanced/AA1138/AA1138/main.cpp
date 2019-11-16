#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef struct node{
	node *left,*right;
	int v;
}node;
int pre[50005],in[50005];
node* newnode(int v){
	node* nd=(node*)malloc(sizeof(node));
	nd->v=v;
	nd->left=nd->right=NULL;
	return nd;
}
node* build(int b1,int e1,int b2,int e2){
	if(b1>e1)return NULL;

	int root=pre[b1];
	node* nd=newnode(root);
	int inr=b2;
	for(;inr<=e2&&in[inr]!=root;inr++)
		;
	int leftnum=inr-b2;
	nd->left=build(b1+1,b1+leftnum,b2,inr-1);
	nd->right=build(b1+leftnum+1,e1,inr+1,e2);

	return nd;
}
int tag=-1;
void post(node* r){
	if(tag!=-1)
		return;

	if(r==NULL)
		return;
	post(r->left);
	post(r->right);
	if(tag==-1)
		tag=r->v;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",pre+i);
	for(int i=0;i<n;i++)
		scanf("%d",in+i);
	node* tree=build(0,n-1,0,n-1);

	post(tree);
	printf("%d",tag);

	getchar();
	getchar();
	return 0;

}