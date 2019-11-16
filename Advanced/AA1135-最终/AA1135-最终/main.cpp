#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct node{
	int v;
	node *left,*right;
}node;
int pre[35];
node* newnode(int v){//新节点
	node* nd=(node*)malloc(sizeof(node));
	nd->left=nd->right=NULL;
	nd->v=v;
	return nd;
}
node* build(int b,int e){//根据先序建树
	if(e<b)return NULL;

	int root=pre[b];
	node* r=newnode(root);

	int rightb=b+1;//找右子树起点
	for(;rightb<=e&&abs(pre[rightb])<abs(root);rightb++)
		;

	r->left=build(b+1,rightb-1);//left
	r->right=build(rightb,e);//right
	return r;
}
bool judgeChild(node* root){//先序遍历，判断红节点的孩子是否都为黑
	if(root==NULL)return true;
	if(root->v<0){
		if(root->left!=NULL&&root->left->v<0)
			return false;
		if(root->right!=NULL&&root->right->v<0)
			return false;
	}
	return judgeChild(root->left)&&judgeChild(root->right);
}
int getNum(node* root){//后序遍历，判断其左右子树到叶节点的路径上是否有相同数量的黑色节点
	if(root==NULL)return 1;
	int left=getNum(root->left);
	int right=getNum(root->right);
	if(left!=right||left==-1||right==-1)return -1;//左右子树到叶节点的路径上的黑色节点数不等
	int self=root->v>0?1:0;//自己是黑色节点，要加一
	return left+self;//此时right==left
}
bool judgeBlackNum(node* root){
	int num=getNum(root);//
	return num!=-1;
}
int main(){
	int k,n;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&n);
		node* tree=NULL;
		for(int j=0;j<n;j++){
			scanf("%d",pre+j);
		}
		tree=build(0,n-1);
		bool ok=(tree->v>0)&&judgeChild(tree)&&judgeBlackNum(tree);

		if(ok)printf("Yes\n");
		else printf("No\n");
	}

	getchar();
	getchar();
	return 0;
}

