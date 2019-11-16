#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define NUM 10005

int p[NUM];
bool v[NUM];

int root(int b){
	int r=b;
	while(p[r]>=0){
		r=p[r];
	}
	while(p[b]>=0){
		int t=p[b];
		p[b]=r;
		b=t;
	}
	return r;
}

void union2(int r1,int r2){
	p[r1]=r2;
}

int main(){
	int n;
	scanf("%d",&n);

	fill(p,p+NUM,-1);
	fill(v,v+NUM,false);
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		if(k==0){
			continue;
		}
		int b;
		scanf("%d",&b);
		v[b]=true;
		for(int j=1;j<k;j++){
			int bt;
			scanf("%d",&bt);
			v[bt]=true;

			int r1=root(b);
			int r2=root(bt);
			if(r1!=r2) union2(r1,r2);
		}
	}
	int bird=0,tree=0;
	for(int i=0;i<NUM;i++){
		if(v[i]){
			bird++;
			if(p[i]<0)
				tree++;
		}
	}
	printf("%d %d\n",tree,bird);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int q1,q2;
		scanf("%d %d",&q1,&q2);
		int r1=root(q1);
		int r2=root(q2);
		if(r1!=r2) printf("No\n");
		else printf("Yes\n");
	}

	getchar();
	getchar();
	return 0;
}