#include<stdio.h>
#include<algorithm>
#include<stack>
using namespace std;
#define INF 0x3fffffff
//120min
int g[501][501];
int c[501];//the current number of bikes
int dis[501];
bool visited[501];
int path[501];
int send[501];//bikes sent from PBMC 
int back[501];//bikes take back to PBMC 

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
	fill(path,path+501,-1);
	fill(send,send+501,INF);
	fill(back,back+501,INF);
	dis[0]=0;send[0]=0;back[0]=0;

	while(1){
		int s=getmindis();
		if(s==-1)
			break;
		visited[s]=true;
		for(int i=0;i<=n;i++){
			int sendsi,backsi;
			if(c[i]<cmax/2){//lack bikes
				if(cmax/2-c[i]>back[s]){
					sendsi=send[s]+(cmax/2-c[i]-back[s]);
					backsi=0;
				}else{
					sendsi=send[s];
					backsi=back[s]-(cmax/2-c[i]);
				}
			}else if(c[i]>cmax/2){//more bikes
				sendsi=send[s];
				backsi=back[s]+(c[i]-cmax/2);
			}else{
				sendsi=send[s];
				backsi=back[s];
			}
			if(!visited[i]&&g[s][i]!=INF&&dis[i]>dis[s]+g[s][i]){
				path[i]=s;
				dis[i]=dis[s]+g[s][i];
				send[i]=sendsi;
				back[i]=backsi;
			}else if(!visited[i]&&g[s][i]!=INF&&dis[i]==dis[s]+g[s][i]){
				if(send[i]>sendsi){
					path[i]=s;
					dis[i]=dis[s]+g[s][i];
					send[i]=sendsi;
					back[i]=backsi;
				}else if(send[i]==sendsi){
					if(back[i]>backsi){
						path[i]=s;
						dis[i]=dis[s]+g[s][i];
						send[i]=sendsi;
						back[i]=backsi;
					}				
				}
			}
		}
	}//while


	printf("%d ",send[sp]);
	int v=sp;stack<int> s;
	while(v!=0){
		s.push(v);
		v=path[v];
	}
	printf("0");
	while(!s.empty()){
		printf("->%d",s.top());
		s.pop();
	}
	printf(" %d",back[sp]);

	getchar();
	getchar();
	return 0;
}