#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int full[30];
int p[30];
int tree[30][2];

void tr(int v,int index){
	full[index]=v;

	if(tree[v][0]!=-1)
		tr(tree[v][0],index*2+1);
	if(tree[v][1]!=-1)
		tr(tree[v][1],index*2+2);
}
int main(){
	int n;
	scanf("%d",&n);

	fill(p,p+n,-1);
	for(int i=0;i<n;i++){
		char c1[5],c2[5];
		scanf("%s %s",c1,c2);

		int l,r;
		if(strcmp(c1,"-")==0){
			l=-1;
		}else{
			sscanf(c1,"%d",&l);
		}
		if(strcmp(c2,"-")==0){
			r=-1;
		}else{
			sscanf(c2,"%d",&r);
		}
		tree[i][0]=l;
		tree[i][1]=r;
		p[l]=i;p[r]=i;
	}

	int root=0;
	while(p[root]!=-1)
		root=p[root];

	fill(full,full+30,-1);
	tr(root,0);
	bool ok=true;
	for(int i=0;i<n;i++){
		if(full[i]<0){
			ok=false;
			break;
		}
	}
	if(ok)printf("YES %d",full[n-1]);
	else printf("NO %d",full[0]);

	getchar();
	getchar();
	return 0;
}