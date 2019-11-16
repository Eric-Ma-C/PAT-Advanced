#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
//24min
int n;
int a[100];
typedef struct node{
	int left,right,value;
}node;
node t[100];
int num=0;
void inorder(int v){
	if(t[v].left!=-1)
		inorder(t[v].left);
	t[v].value=a[num++];
	if(t[v].right!=-1)
		inorder(t[v].right);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&t[i].left,&t[i].right);}
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	sort(a,a+n);
	inorder(0);

	queue<int> q;
	if(t[0].left!=-1) q.push(t[0].left);
	if(t[0].right!=-1) q.push(t[0].right);
	printf("%d",t[0].value);
	while(!q.empty()){
		int i=q.front();
		q.pop();
		printf(" %d",t[i].value);

		if(t[i].left!=-1)
			q.push(t[i].left);
		if(t[i].right!=-1)
			q.push(t[i].right);

	}
	getchar();
	getchar();
	return 0;
}