#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int id=0;
typedef struct node{
	int v,id;
	node *left,*right;
}node;
node root;
int level[2000]={0};
void insertBST(node* root,node *n,int lev){
	if(n->v>root->v){
		if(root->right==NULL){
			root->right=n;
			level[lev]++;
			return;
		}else{
			insertBST(root->right,n,lev+1);
		}
	}else{
		if(root->left==NULL){
			root->left=n;
			level[lev]++;
			return;
		}else{
			insertBST(root->left,n,lev+1);
		}
	}

}
void insert(int v){
	node* n=(node*)malloc(sizeof(node));
	n->v=v;
	n->left=NULL;
	n->right=NULL;
	n->id=id++;
	insertBST(&root,n,1);
}
int main(){
	int n;
	scanf("%d",&n);
	int t;
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		if(i==0){
			root.v=t;root.id=id++;
			root.left=NULL;
			root.right=NULL;
		}else{
			insert(t);
		}
	}

	level[0]=1;int i=0;
	for(;level[i]!=0;i++)
		;
	int lev1=level[i-1];
	int lev2=level[i-2];
	printf("%d + %d = %d",lev1,lev2,lev1+lev2);

	getchar();
	getchar();
	return 0;
}