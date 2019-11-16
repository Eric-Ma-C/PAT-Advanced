#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
//段错误，邻接表太大？
vector<int> nextp[100002];//邻接表
int main(){
	int n;
	double p,r;
	scanf("%d %lf %lf",&n,&p,&r);
	int *pre=(int *)malloc(sizeof(int)*n);
	int root=0;
	for(int i=0;i<n;i++){
		scanf("%d",pre+i);
		if(pre[i]==-1) root=i;
	}
	queue<int> q;
	for(int i=0;i<n;i++){
		if(pre[i]==root){
			q.push(i);
		}
		nextp[pre[i]].push_back(i);
	}
	int tag=q.front(),level=0,num=0;bool refresh=0;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		if(t==tag){
			level++;num=0;refresh=1;
		}
		num++;
		for(int i=0;i<nextp[t].size();i++){
			q.push(nextp[t][i]);
			if(refresh){refresh=0;tag=nextp[t][i];}
		}

	}

	double pmax=p;
	for(int i=0;i<level;i++)
		pmax=pmax*(1+r/100.0);

	printf("%.2f %d",pmax,num);
	getchar();
	getchar();
	return 0;
}