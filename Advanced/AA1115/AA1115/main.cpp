#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int id=0;
typedef struct node{
	int v,id;
	node *left,*right;
}node;
node root;
void insertBST(node* root,node *n){
	if(n->v>root->v){
		if(root->right==NULL){
			root->right=n;
			return;
		}else{
			insertBST(root->right,n);
		}
	}else{
		if(root->left==NULL){
			root->left=n;
			return;
		}else{
			insertBST(root->left,n);
		}
	}

}
void insert(int v){
	node* n=(node*)malloc(sizeof(node));
	n->v=v;
	n->left=NULL;
	n->right=NULL;
	n->id=id++;
	insertBST(&root,n);
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
	queue<node> q;
	q.push(root);
	int lev1=1;
	int lev2=0;int tag=root.id;bool pre=false;
	while(!q.empty()){
		node nt=q.front();
		q.pop();

		if(tag==nt.id){
			pre=true;lev2=lev1;lev1=1;
		}else{
			lev1++;
		}

		if(nt.left!=NULL){
			if(pre){ tag=nt.left->id;pre=false;}
			q.push(*nt.left);
		}if(nt.right!=NULL){
			if(pre){ tag=nt.right->id;pre=false;}
			q.push(*nt.right);
		}
	}
	printf("%d + %d = %d",lev1,lev2,lev1+lev2);

	getchar();
	getchar();
	return 0;
}