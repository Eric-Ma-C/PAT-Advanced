#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
//42min
int in[35];
int post[35];
int n;
typedef struct node{//树节点
	int v;
	node *left,*right;
}node;
node* tree;
vector<int> level;//用于层序输出
node* newnode(int v){
	node *nd=(node*)malloc(sizeof(node));
	nd->v=v;
	nd->left=NULL;
	nd->right=NULL;
	return nd;
}
void build(int b1,int e1,int b2,int e2,node* root,bool isleft){//递归建树
	if(e1<b1) return ;
	int rootv=post[e2];
	node* nd=newnode(rootv);
	if(root==NULL)
		tree=nd;
	else{
		if(isleft)
			root->left=nd;
		else
			root->right=nd;
	}
	int inr=b1;
	for(;in[inr]!=rootv;inr++)
		;
	int lchnum=inr-b1;
	build(b1,inr-1,b2,b2+lchnum-1,nd,true);//left
	build(inr+1,e1,b2+lchnum,e2-1,nd,false);//right
}
void print(bool isLR){//正反序输出
	if(isLR){
		for(int i=0;i<level.size();i++){
			if(level[i]!=tree->v)printf(" ");
			printf("%d",level[i]);
		}
	}else{
		for(int i=level.size()-1;i>=0;i--){
			if(level[i]!=tree->v)printf(" ");
			printf("%d",level[i]);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",in+i);
	}
	for(int i=0;i<n;i++){
		scanf("%d",post+i);
	}
	build(0,n-1,0,n-1,NULL,true);//建树
	queue<node> q;
	q.push(*tree);
	int tag=tree->v;bool pre,lr=true;
	while(!q.empty()){
		node t=q.front();
		q.pop();
		if(tag==t.v){
			pre=true;
			print(lr);//输出上一层
			lr=!lr;
			level.clear();
		}
		level.push_back(t.v);

		if(t.left!=NULL){
			if(pre){
				pre=false;
				tag=t.left->v;
			}
			q.push(*t.left);
		}
		if(t.right!=NULL){
			if(pre){
				pre=false;
				tag=t.right->v;
			}
			q.push(*t.right);
		}
	}
	print(lr);

	getchar();
	getchar();
	return 0;
}

