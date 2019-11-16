#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct node{
	int v,h,id;
	node *left,*right;
}node;
node* tree=NULL;
node* newnode(int v){
	node* nd=(node*)malloc(sizeof(node));
	nd->v=v;
	nd->h=1;//��ʼ�߶�Ϊ1
	nd->left=nd->right=NULL;
	return nd;
}
int geth(node* root){
	if(root==NULL)
		return 0;
	return root->h;
}
int getbf(node *root){
	if(root==NULL)
		return 0;
	return geth(root->left)-geth(root->right);
}
void updateh(node *root){
	if(root==NULL)
		return;
	root->h=max(geth(root->left),geth(root->right))+1;
}
void L(node* &root){//����
	node* tmp=root->right;
	root->right=tmp->left;
	tmp->left=root;
	updateh(root);
	updateh(tmp);//ע��˳��
	root=tmp;
}
void R(node* &root){//����
	node* tmp=root->left;
	root->left=tmp->right;
	tmp->right=root;
	updateh(root);
	updateh(tmp);//ע��˳��
	root=tmp;
}
void insertv(node* &root,int v){//�����½ڵ�
	if(root==NULL){
		root=newnode(v);
		return ;
	}
	if(v>root->v){
		insertv(root->right,v);
		updateh(root);
		if(getbf(root)==-2){
			if(getbf(root->right)==-1){//RR
				L(root);
			}else if(getbf(root->right)==1){//RL
				R(root->right);
				L(root);
			}
		}
	}else{
		insertv(root->left,v);
		updateh(root);
		if(getbf(root)==2){
			if(getbf(root->left)==1){//LL
				R(root);
			}else if(getbf(root->left)==-1){//LR
				L(root->left);
				R(root);
			}
		}
	}
}
void preorder(node *root,int id){
	root->id=id;
	if(root->left!=NULL){
		preorder(root->left,id*2);
	}
	if(root->right!=NULL){
		preorder(root->right,id*2+1);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		insertv(tree,t);
	}
	preorder(tree,1);//��id���ж��Ƿ���ȫ������

	queue<node> q;
	q.push(*tree);
	bool tag[350]={0};
	while(!q.empty()){
		node nd=q.front();
		q.pop();

		tag[nd.id]=true;
		if(nd.v!=tree->v)printf(" ");
		printf("%d",nd.v);

		if(nd.left!=NULL)
			q.push(*nd.left);
		if(nd.right!=NULL)
			q.push(*nd.right);
	}
	bool ok=true;
	for(int i=1;i<=n;i++){
		if(!tag[i]){ok=false;break;}
	}
	if(ok)printf("\nYES");
	else printf("\nNO");

	getchar();
	getchar();
	return 0;
}

