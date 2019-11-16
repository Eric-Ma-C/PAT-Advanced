#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

typedef struct way{
	int dis;
	int cost;
}way;
int MAX=0x3fffffff;
int n,m,s,d;
bool visited[500];
int path[500];
int dist[500];
int cost[500];

int getmin(){
	int min=-1,mindis=MAX,mincost=MAX;
	for(int i=0;i<n;i++){
		if(!visited[i]&&dist[i]<=mindis){
			if(dist[i]==mindis&&cost[i]>=mincost)
				continue;
			min=i;mindis=dist[i];mincost=cost[i];
		}
	}

	return min;
}

void printpre(int i){
	if(path[i]==-1){
		printf("%d ",i);
		return;
	}

	printpre(path[i]);
	printf("%d ",i);

}
int main(){
	scanf("%d %d %d %d",&n,&m,&s,&d);

	way *list=(way*)malloc(sizeof(way)*n*n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			list[j*n+i].cost=MAX;
			list[j*n+i].dis=MAX;
			list[i*n+j].cost=MAX;
			list[i*n+j].dis=MAX;
		}
		
		int c1,c2,dis,cos;
		for(int i=0;i<m;i++){
			scanf("%d %d %d %d",&c1,&c2,&dis,&cos);

			list[c1*n+c2].dis=dis;
			list[c1*n+c2].cost=cos;
			list[c2*n+c1].dis=dis;
			list[c2*n+c1].cost=cos;
		}


		fill(visited,visited+500,false);
		fill(path,path+500,-1);
		fill(dist,dist+500,MAX);
		fill(cost,cost+500,MAX);

		//dijkstra
		/*for(int i=0;i<n;i++){
			dist[i]=list[i*n+s].dis;
			cost[i]=list[i*n+s].cost;
			if(list[i*n+s].dis!=MAX)
				path[i]=s;
		}*/
		dist[s]=0;
		path[s]=-1;
		//visited[s]=true;
		cost[s]=0;

		while(1){
			int node=getmin();
			if(node==-1)
				break;
			visited[node]=true;
			for(int i=0;i<n;i++){
				if(!visited[i]&&list[i*n+node].dis!=MAX&&dist[i]>=dist[node]+list[node*n+i].dis){
					if(dist[i]==dist[node]+list[node*n+i].dis
						&&cost[i]<=cost[node]+list[node*n+i].cost){
							continue;
					}
					dist[i]=dist[node]+list[node*n+i].dis;
					path[i]=node;
					cost[i]=cost[node]+list[node*n+i].cost;
				}

			}

		}

		printpre(d);
		printf("%d %d",dist[d],cost[d]);

		getchar();
		getchar();
		return 0;
}