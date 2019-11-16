#include<stdio.h>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
#define INF 0x3fffffff
int num[505],dis[505],tmpmax;
int g[505][505];
bool inq[505]={0};
set<int> pre[505];
int n,m,c1,c2;
int ans1=0,ans2=0;
void dfs(int v){
	tmpmax+=num[v];
	if(v==c1){
		if(tmpmax>ans2)
			ans2=tmpmax;
		ans1++;
		tmpmax-=num[v];
		return;
	}

	for(auto it=pre[v].begin();it!=pre[v].end();it++){
		dfs(*it);
	}
	tmpmax-=num[v];
}
int main(){

	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	for(int i=0;i<n;i++)
		scanf("%d",num+i);
	fill(g[0],g[504]+505,INF);
	for(int i=0;i<m;i++){
		int t1,t2,l;
		scanf("%d%d%d",&t1,&t2,&l);
		g[t1][t2]=l;
		g[t2][t1]=l;
	}
	fill(dis,dis+n,INF);
	//fill(pre,pre+n,-1);
	dis[c1]=0;
	queue<int> q;
	q.push(c1);
	inq[c1]=true;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		inq[t]=false;
		for(int i=0;i<n;i++){
			if(g[t][i]!=INF&&dis[t]+g[t][i]<=dis[i]){
				if(dis[t]+g[t][i]<dis[i]){
					pre[i].clear();
				}
				dis[i]=dis[t]+g[t][i];
				pre[i].insert(t);

				if(!inq[i]){
					q.push(i);
					inq[i]=true;
				}
			}
		}
	}
	tmpmax=0;
	dfs(c2);
	printf("%d %d",ans1,ans2);

	getchar();
	getchar();
	return 0;}