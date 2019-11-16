#include<stdio.h>
#include<queue>
//80min
int post[30],in[30];
int left[30]={0},right[30]={0};
int buildT(int p1,int p2,int i1,int i2){
	int root=post[p2];
	if(p1==p2){
		return root;
	}else if(p1>p2){
		return 0;
	}
	int ri=i1;
	for(;ri<=i2;ri++){
		if(in[ri]==root) break;
	}
	int leftN=ri-i1;
	left[root]=buildT(p1,p1+leftN-1,i1,ri-1);//left
	right[root]=buildT(p1+leftN,p2-1,ri+1,i2);//right

	return root;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",post+i);
	for(int i=0;i<n;i++)
		scanf("%d",in+i);

	buildT(0,n-1,0,n-1);

	std::queue<int> q;
	int root=post[n-1];
	printf("%d",root);
	if(left[root]) q.push(left[root]);
	if(right[root]) q.push(right[root]);
	while(!q.empty()){
		int root=q.front();
		q.pop();printf(" %d",root);
		if(left[root]) q.push(left[root]);
		if(right[root]) q.push(right[root]);
	}

	getchar();
	getchar();
	return 0;
}