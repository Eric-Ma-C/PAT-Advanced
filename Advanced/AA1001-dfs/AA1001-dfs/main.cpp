#include<stdio.h>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
#define INF 0x3fffffff

int g[501][501];
int c[501];//the current number of bikes
int dis[501];
bool visited[501];
vector<int> path[501];

int cmax,n,sp,m;
int getmindis(){//find shortest station that not visited
	int mindis=INF,mins=-1;
	for(int i=0;i<n;i++){
		if(dis[i]<mindis&&!visited[i]){
			mindis=dis[i];mins=i;
		}
	}
	return mins;
}
vector<int> tmpPath;
int finalpath[501];
int sendmin=INF;//bikes sent from PBMC 
int backmin=INF;//bikes take back to PBMC 
void dfs(int v){
	if(v==0){
		int send=0,back=0;
		for(int i=tmpPath.size()-1;i>=0;i--){
			int lack=cmax/2-c[tmpPath[i]]-back;
			if(lack<0){ back=-lack;lack=0;}
			else back=0;
			send+=lack;
		}
		if(send<sendmin||(send==sendmin&&back<backmin)){
			sendmin=send;
			backmin=back;
			fill(finalpath,finalpath+501,-1);int j=0;
			for(int i=tmpPath.size()-1;i>=0;i--){
				finalpath[j++]=tmpPath[i];
			}
		}
		return;
	}
	tmpPath.push_back(v);
	for(int i=0;i<path[v].size();i++){
		dfs(path[v][i]);
	}
	tmpPath.pop_back();
}
int main(){
	scanf("%d %d %d %d",&cmax,&n,&sp,&m);
	for(int i=0;i<n;i++){
		scanf("%d",c+i+1);
	}
	fill(&g[0][0],&g[500][501],INF);
	int s1,s2,t;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&s1,&s2,&t);
		g[s1][s2]=t;
		g[s2][s1]=t;
	}
	fill(visited,visited+501,false);
	fill(dis,dis+501,INF);
	dis[0]=0;

	while(1){
		int s=getmindis();
		if(s==-1)
			break;
		visited[s]=true;
		for(int i=0;i<=n;i++){
			if(!visited[i]&&g[s][i]!=INF&&dis[i]>=dis[s]+g[s][i]){
				if(dis[i]>dis[s]+g[s][i]){
					path[i].clear();
				}
				dis[i]=dis[s]+g[s][i];
				path[i].push_back(s);
			}
		}
	}//while
	dfs(sp);

	printf("%d ",sendmin);
	printf("0");int i=0;
	while(finalpath[i]!=-1){
		printf("->%d",finalpath[i++]);
	}
	printf(" %d",backmin);

	getchar();
	getchar();
	return 0;
}