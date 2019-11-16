#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct node{
	int v;
	node *left,*right;
}node;
//node* tree=NULL;
int in[35],pre[35];
node* newnode(int v){
	node* nd=(node*)malloc(sizeof(node));
	nd->left=nd->right=NULL;
	nd->v=v;
	return nd;
}

node* build(int b1,int e1,int b2,int e2){//注意要用引用
	if(e1<b1)return NULL;

	int root=pre[b1];
	node* r=newnode(root);

	int inr=b2;
	for(;inr<=e2&&abs(in[inr])!=abs(root);inr++)
		;
	if(abs(in[inr])!=abs(root))
		return r;//这个判断不能少，否则段错误，不知道为什么

	int leftnum=inr-b2;
	r->left=build(b1+1,b1+leftnum,b2,inr-1);//left
	r->right=build(b1+leftnum+1,e1,inr+1,e2);//right
	return r;
}
bool cmp(int n1,int n2){
	return abs(n1)<abs(n2);
}
bool judgeChild(node* root){
	if(root==NULL)return true;
	if(root->v<0){
		if(root->left!=NULL&&root->left->v<0)
			return false;
		if(root->right!=NULL&&root->right->v<0)
			return false;
	}
	return judgeChild(root->left)&&judgeChild(root->right);
}
int getNum(node* root){
	if(root==NULL)return 1;
	int left=getNum(root->left);
	int right=getNum(root->right);
	if(left!=right||left==-1||right==-1)return -1;
	int self=root->v>0?1:0;
	return left+self;
}
bool judgeBlackNum(node* root){
	int num=getNum(root);
	return num!=-1;
}
void buildTree(int v,node* &root){
	if(root==NULL){
		root=newnode(v);
	}else{
		if(abs(root->v)>abs(v))
			buildTree(v,root->left);
		else
			buildTree(v,root->right);
	}
}
int main(){
	int k,n;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&n);
		if(n==0){
		printf("Yes\n");
		continue;
		}
		node* tree=NULL;
		for(int j=0;j<n;j++){
			scanf("%d",pre+j);
			in[j]=pre[j];
		    //buildTree(pre[j],tree);

		}
		
		sort(in,in+n,cmp);
		tree=build(0,n-1,0,n-1);

		bool ok=(tree->v>0)&&judgeChild(tree)&&judgeBlackNum(tree);

		if(ok)printf("Yes\n");
		else printf("No\n");

	}

	getchar();
	getchar();
	return 0;
}

