#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

typedef struct node{
	string str;
	int left,right;
}node;
int p[35];
node tree[35];
int root;

void print(int i){
	bool hasl=(tree[i].left!=-1);
	bool hasr=(tree[i].right!=-1);

	if((hasl||hasr)&&i!=root)
		printf("(");
	if(hasl)
		print(tree[i].left);

	printf("%s",tree[i].str.c_str());

	if(hasr)
		print(tree[i].right);
	if((hasl||hasr)&&i!=root)
		printf(")");
}
int main(){
	int n;
	scanf("%d",&n);
	fill(p,p+n+1,-1);
	for(int i=1;i<=n;i++){
		char c[15];
		scanf("%s %d %d",c,&tree[i].left,&tree[i].right);
		tree[i].str=string(c);
		if(tree[i].left!=-1)
			p[tree[i].left]=i;
		if(tree[i].right!=-1)
			p[tree[i].right]=i;

	}
	root=1;
	while(p[root]>0){
		root=p[root];
	}

	print(root);

	getchar();
	getchar();
	return 0;
}