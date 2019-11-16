#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
int num[25]; 
//180min
typedef struct node{
	int val,height;
	node *left,*right;
}node;
node* newnode(int v){
	node* n=(node*)malloc(sizeof(node));
	n->height=1;
	n->val=v;
	n->left=NULL;
	n->right=NULL;
	return n;
}
int geth(node *&root){
	if(root==NULL)
		return 0;
	return root->height;
}
void updateH(node *&root){
	root->height=std::max(geth(root->left),geth(root->right))+1;
}
int getBanFac(node *&n){
	if(n==NULL)
		return 0;
	return geth(n->left)-geth(n->right);
}
void left(node *&root){//左旋
	node *tmp=root->right;
	root->right=tmp->left;
	tmp->left=root;
	updateH(root);//先更新下面的
	updateH(tmp);//再更新上面的
	root=tmp;
}
void right(node *&root){//右旋
	node *tmp=root->left;
	root->left=tmp->right;
	tmp->right=root;
	updateH(root);//先更新下面的
	updateH(tmp);//再更新上面的
	root=tmp;
}
void insertn(node *&n,int v){
	if(n==NULL){
		n=newnode(v);
		return;
	}
	if(n->val>v){
		insertn(n->left,v);
		updateH(n);
		int fac1=getBanFac(n);
		int fac2=getBanFac(n->left);
		if(fac1==2){
			if(fac2==1){//LL
				right(n);
			}else if(fac2==-1){//LR
				left(n->left);
				right(n);
			}
		}
	}else{
		insertn(n->right,v);
		updateH(n);
		int fac1=getBanFac(n);
		int fac2=getBanFac(n->right);
		if(fac1==-2){
			if(fac2==-1){//RR
				left(n);
			}else if(fac2==1){//RL
				right(n->right);
				left(n);
			}
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",num+i);
	}
	node* root=NULL;
	for(int i=0;i<t;i++){
		insertn(root,num[i]);
	}

	printf("%d",root->val);
	getchar();
	getchar();
	return 0;
}