#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef struct node{
	int v;
	node *left,*right;
}node;
node* tree=NULL;

int in[35],pre[35];

node* newnode(int v){
	node* nd=(node*)malloc(sizeof(node));
	nd->left=nd->right=NULL;
	nd->v=v;
	return nd;
}

void build(int b1,int e1,int b2,int e2,node* &r){//注意要用引用
	if(e1<b1)return;

	int root=pre[b1];
	r=newnode(root);

	int inr=b2;
	for(;inr<=e2&&in[inr]!=root;inr++)
		;
	int leftnum=inr-b2;
	build(b1+1,b1+leftnum,b2,inr-1,r->left);//left
	build(b1+leftnum+1,e1,inr+1,e2,r->right);//right
}
bool cmp(int n1,int n2){
	return abs(n1)<abs(n2);
}
int blacknum,tmp;
bool judgenode(node *r,bool redp){
	bool hasl=(r->left!=NULL);
	bool hasr=(r->right!=NULL);

	//printf("<%d>",r->v);
	if(r->v<0){//red
		if(redp)
			return false;
		redp=true;
	}else{//black
		redp=false;
		tmp++;
	}
	if(!hasl&&!hasr){
		if(blacknum==-1)
			blacknum=tmp;
		else{
			if(blacknum!=tmp)
				return false;
		}
	}
	bool okl=true,okr=true;
	if(hasl){
		okl=judgenode(r->left,redp);
		if(r->left->v>0)
			tmp--;
	}if(hasr){
		okr=judgenode(r->right,redp);
		if(r->right->v>0)
			tmp--;
	}
	return okl&&okr;
}

bool dfs(node *r){
	bool hasl=(r->left!=NULL);
	bool hasr=(r->right!=NULL);

	if(!hasl&&!hasr){
		return true;
	}
	blacknum=-1;tmp=0;
	int ok=judgenode(r,r->v<0?true:false);

	bool okl=true,okr=true;
	if(hasl){
		okl=dfs(r->left);
	}
	if(hasr){
		okr=dfs(r->right);
	}
	return ok&&okl&&okr;
}
bool judge(){
	/*if(tree->v<0)
	return false;*/

	return dfs(tree);

}
int main(){
	int k,n;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&n);
		for(int j=0;j<n;j++){
			scanf("%d",pre+j);
			in[j]=pre[j];
		}
		sort(in,in+n,cmp);
		build(0,n-1,0,n-1,tree);

		bool ok=judge();
		if(ok)printf("Yes\n");
		else printf("No\n");

	}


	getchar();
	getchar();
	return 0;
}