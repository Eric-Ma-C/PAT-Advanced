#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#define INF 0x3fffffff
using namespace std;

typedef struct city{
	char name[4];
	int happy;
}city;
int cost[202][202];
int finalpath[202],dis[202],visited[202]={0};
int n,k,happymax=0,citynum=INF,pathnum=0;
map<string,int> toint;//city name to index
vector<int> tmpp,path[202];
city* cities;

void dfs(int v){
	if(v==0){
		pathnum++; int h=0;
		for(int i=0;i<tmpp.size();i++){
			h+=cities[tmpp[i]].happy;
		}
		if(h>happymax||(h==happymax&&tmpp.size()<citynum)){
			happymax=h; citynum=tmpp.size();
			fill(finalpath,finalpath+202,-1);
			int j=0;
			for(int i=tmpp.size()-1;i>=0;i--){
				finalpath[j++]=tmpp[i];
			}
		}
		return;
	}
	tmpp.push_back(v);
	for(int i=0;i<path[v].size();i++){
		dfs(path[v][i]);
	}
	tmpp.pop_back();
}
int main(){
	scanf("%d %d",&n,&k);
	cities=(city*)malloc(sizeof(city)*n);
	scanf("%s",&cities[0].name);
	toint[cities[0].name]=0;
	for(int i=1;i<n;i++){
		scanf("%s %d",&cities[i].name,&cities[i].happy);
		string str=cities[i].name;
		toint[str]=i;
	}
	char c1[4],c2[4];int t;
	fill(cost[0],cost[201]+202,INF);
	for(int i=0;i<k;i++){
		scanf("%s %s %d",c1,c2,&t);
		string s1(c1);string s2(c2);
		cost[toint[s1]][toint[s2]]=t;
		cost[toint[s2]][toint[s1]]=t;
	}
	
	fill(dis,dis+202,INF);
	dis[0]=0;
	while(1){
		int t=-1,mindis=INF;
		for(int i=0;i<n;i++){
			if(!visited[i]&&dis[i]<mindis){
				mindis=dis[i];
				t=i;
			}
		}
		if(t==-1)
			break;
		visited[t]=true;
		for(int i=0;i<n;i++){
			if(!visited[i]&&cost[i][t]!=INF){
				if(dis[i]>=dis[t]+cost[i][t]){
					if(dis[i]>dis[t]+cost[i][t])
						path[i].clear();
					dis[i]=dis[t]+cost[i][t];
					path[i].push_back(t);
				}
			}
		}
	}//while
	string roms("ROM");
	dfs(toint[roms]);

	printf("%d %d %d %d\n",pathnum,dis[toint[roms]],happymax,happymax/citynum);
	printf("%s",cities[0].name);
	
	for(int i=0;finalpath[i]!=-1;i++)
		printf("->%s",cities[finalpath[i]].name);
	
	getchar();
	getchar();
	return 0;
}