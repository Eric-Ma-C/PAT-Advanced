#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//32min
typedef struct node{
	int left,right;
}node;
node tree[20];
node rtree[20];
int p[20];//parent
int root;
vector<int> in;
void inorder(int v){
	if(rtree[v].left>=0)inorder(rtree[v].left);
	in.push_back(v);
	if(rtree[v].right>=0)inorder(rtree[v].right);
}
int main(){
	int n;
	scanf("%d",&n);

	fill(p,p+n,-1);
	for(int i=0;i<n;i++){
		char l,r;
		getchar();
		scanf("%c %c",&l,&r);
		int le=-1,ri=-1;
		if(l!='-'){le=l-'0';p[le]=i;}
		if(r!='-'){ri=r-'0';p[ri]=i;}
		tree[i].left=le;
		tree[i].right=ri;
		rtree[i].right=le;
		rtree[i].left=ri;
	}

	for(root=0;p[root]!=-1;root=p[root])
		;

	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int tmp=q.front();
		q.pop();
		if(tmp!=root)printf(" ");
		printf("%d",tmp);
		if(rtree[tmp].left>=0)q.push(rtree[tmp].left);
		if(rtree[tmp].right>=0)q.push(rtree[tmp].right);
	}
	printf("\n");

	inorder(root);
	for(int i=0;i<in.size();i++){
		if(i!=0)
			printf(" ");
		printf("%d",in[i]);
	}

	getchar();
	getchar();
	return 0;
}