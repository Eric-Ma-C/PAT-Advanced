#include<stdio.h>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
#define INF 0x3fffff

int g[1020][1020];
int d[15];//距离居住区最近距离
int sum[15];//距离居住区距离和
int N,M,K,dmax;
void dijkstra(int n){
	int dis[1020];bool visited[1020];
	fill(dis,dis+1020,INF);
	fill(visited,visited+1020,false);
	dis[n]=0;
	while(1){
		int t=-1;int mindis=INF;
		for(int i=1;i<=N+M;i++){
			if(!visited[i]&&dis[i]<mindis){
				mindis=dis[i];
				t=i;
			}
		}
		if(t==-1)
			break;
		visited[t]=1;
		for(int i=1;i<=N+M;i++){
			if(!visited[i]&&g[i][t]!=INF&&dis[i]>dis[t]+g[i][t]){
				dis[i]=dis[t]+g[i][t];
			}
		}
	}
	int mindis=INF,sumdis=0;
	for(int i=1;i<=N;i++){
		if(dis[i]>dmax){
			mindis=INF;
			sumdis=INF;
			break;
		}
		sumdis+=dis[i];
		if(dis[i]<mindis){
			mindis=dis[i];
		}
	}

	d[n-N]=mindis;
	sum[n-N]=sumdis;

}
int getindex(char *p){
	int index=0;

	if(p[0]=='G'){
		string st(p+1);
		stringstream stream(st);
		stream>>index;
		index+=N;
	}else{
		string st(p);
		stringstream stream(st);
		stream>>index;
	}
	return index;
}
int main(){
	scanf("%d %d %d %d",&N,&M,&K,&dmax);

	fill(g[0],g[1019]+1020,INF);
	char p1[10],p2[10];int ip1,ip2,dis;
	for(int i=0;i<K;i++){
		scanf("%s %s %d",p1,p2,&dis);
		ip1=getindex(p1);
		ip2=getindex(p2);
		g[ip1][ip2]=dis;
		g[ip2][ip1]=dis;
	}

	for(int k=1;k<=M;k++){
		dijkstra(k+N);
	}
	int ans=-1,maxmin=0,summin=INF;
	for(int i=1;i<=M;i++){
		if(d[i]==INF)
			continue;
		if(d[i]>maxmin||(d[i]==maxmin&&sum[i]<summin)){
			maxmin=d[i];ans=i;summin=sum[i];
		}
	}

	if(ans==-1)
		printf("No Solution");
	else{
		printf("G%d\n",ans);
		printf("%.1f %.1f",maxmin*1.0,summin*1.0/N);
	}
	getchar();
	getchar();
	return 0;
}