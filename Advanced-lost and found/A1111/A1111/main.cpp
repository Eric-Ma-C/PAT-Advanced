#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 0x3fffffff
#define NUM 505

int from,to;
int N,M;
int glen[NUM][NUM],gtime[NUM][NUM];
int path1[NUM],path2[NUM];
int dis[NUM],time1[NUM];
int time2[NUM],step[NUM];
bool visited[NUM];//,visited2[NUM];

void dijkstra1(){
	fill(dis,dis+N,INF);
	fill(time1,time1+N,INF);
	fill(path1,path1+N,-1);
	fill(visited,visited+N,false);
	dis[from]=0;time1[from]=0;
	while(1){
		int t=-1,mindis=INF;
		for(int i=0;i<N;i++){
			if(!visited[i]&&dis[i]<mindis){
				mindis=dis[i];t=i;
			}
		}
		if(t==-1)
			break;
		visited[t]=true;
		for(int i=0;i<N;i++){
			if(!visited[i]&&glen[t][i]!=INF&&dis[i]>=dis[t]+glen[t][i]){
				if(dis[i]==dis[t]+glen[t][i]&&time1[i]<=time1[t]+gtime[t][i]){
					continue;
				}
				dis[i]=dis[t]+glen[t][i];
				time1[i]=time1[t]+gtime[t][i];
				path1[i]=t;
			}
		}
	}//while
}
void dijkstra2(){
	fill(step,step+N,INF);
	fill(time2,time2+N,INF);
	fill(path2,path2+N,-1);
	fill(visited,visited+N,false);
	time2[from]=0;step[from]=0;
	while(1){
		int t=-1,mintime=INF;
		for(int i=0;i<N;i++){
			if(!visited[i]&&time2[i]<mintime){
				mintime=time2[i];t=i;
			}
		}
		if(t==-1)
			break;
		visited[t]=true;
		for(int i=0;i<N;i++){
			if(!visited[i]&&gtime[t][i]!=INF&&time2[i]>=time2[t]+gtime[t][i]){
				if(time2[i]==time2[t]+gtime[t][i]&&step[i]<=step[t]+1){
					continue;
				}
				time2[i]=time2[t]+gtime[t][i];
				step[i]=step[t]+1;
				path2[i]=t;
			}
		}
	}//while
}
int main(){
	scanf("%d%d",&N,&M);

	fill(glen[0],glen[NUM-1]+NUM,INF);
	fill(gtime[0],gtime[NUM-1]+NUM,INF);
	int v1,v2,oneway,len,t;
	for(int i=0;i<M;i++){
		scanf("%d%d%d%d%d",&v1,&v2,&oneway,&len,&t);
		if(oneway==0){
			glen[v2][v1]=len;
			gtime[v2][v1]=t;
		}
		glen[v1][v2]=len;
		gtime[v1][v2]=t;
	}
	scanf("%d%d",&from,&to);

	dijkstra1();
	dijkstra2();

	vector<int> p1,p2;
	for(int i=to;i!=-1;i=path1[i])
		p1.push_back(i);
	for(int i=to;i!=-1;i=path2[i])
		p2.push_back(i);

	bool same=false;
	if(p1.size()==p2.size()){
		int i=0;
		for(;i<p1.size();i++){
			if(p1[i]!=p2[i]){
				break;
			}
		}
		if(i==p1.size())
			same=true;
	}

	if(same){
		printf("Distance = %d; Time = %d: %d",dis[to],time1[to],from);
		for(int i=p1.size()-2;i>=0;i--){
			printf(" -> %d",p1[i]);
		}
	}else{
		printf("Distance = %d: %d",dis[to],from);
		for(int i=p1.size()-2;i>=0;i--){
			printf(" -> %d",p1[i]);
		}
		printf("\nTime = %d: %d",time2[to],from);
		for(int i=p2.size()-2;i>=0;i--){
			printf(" -> %d",p2[i]);
		}
	}

	getchar();
	getchar();
	return 0;
}