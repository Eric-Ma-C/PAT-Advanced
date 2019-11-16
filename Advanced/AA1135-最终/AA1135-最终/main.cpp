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
node* newnode(int v){//�½ڵ�
	node* nd=(node*)malloc(sizeof(node));
	nd->left=nd->right=NULL;
	nd->v=v;
	return nd;
}
node* build(int b,int e){//����������
	if(e<b)return NULL;

	int root=pre[b];
	node* r=newnode(root);

	int rightb=b+1;//�����������
	for(;rightb<=e&&abs(pre[rightb])<abs(root);rightb++)
		;

	r->left=build(b+1,rightb-1);//left
	r->right=build(rightb,e);//right
	return r;
}
bool judgeChild(node* root){//����������жϺ�ڵ�ĺ����Ƿ�Ϊ��
	if(root==NULL)return true;
	if(root->v<0){
		if(root->left!=NULL&&root->left->v<0)
			return false;
		if(root->right!=NULL&&root->right->v<0)
			return false;
	}
	return judgeChild(root->left)&&judgeChild(root->right);
}
int getNum(node* root){//����������ж�������������Ҷ�ڵ��·�����Ƿ�����ͬ�����ĺ�ɫ�ڵ�
	if(root==NULL)return 1;
	int left=getNum(root->left);
	int right=getNum(root->right);
	if(left!=right||left==-1||right==-1)return -1;//����������Ҷ�ڵ��·���ϵĺ�ɫ�ڵ�������
	int self=root->v>0?1:0;//�Լ��Ǻ�ɫ�ڵ㣬Ҫ��һ
	return left+self;//��ʱright==left
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

