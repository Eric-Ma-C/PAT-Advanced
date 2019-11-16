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
	int happ;
}city;
int cost[202][202];
map<string,int> toint;//city name to index

//vector<int> tmppath;
int path[202];
int visited[202]={0};
int n,k;
city* cities;
//int rom,costmin=INF,happmax=0,num=INF,
int pathnum[202];

int dis[202];
int happy[202];
int cnum[202];
void printp(int v){
	if(v==0)
		return;
	printp(path[v]);
	printf("->%s",cities[v].name);
}
int main(){

	scanf("%d %d",&n,&k);
	cities=(city*)malloc(sizeof(city)*n);
	scanf("%s",&cities[0].name);
	toint[cities[0].name]=0;

	for(int i=0;i<n-1;i++){
		scanf("%s %d",&cities[i+1].name,&cities[i+1].happ);
		string str=cities[i+1].name;
		toint[str]=i+1;
	}
	char c1[4],c2[4];int t;
	fill(cost[0],cost[201]+202,INF);
	for(int i=0;i<k;i++){
		scanf("%s %s %d",c1,c2,&t);
		string s1(c1);string s2(c2);
		cost[toint[s1]][toint[s2]]=t;
		cost[toint[s2]][toint[s1]]=t;
	}
	string roms("ROM");
	int rom=toint[roms];

	fill(pathnum,pathnum+202,0);
	fill(path,path+202,-1);
	fill(dis,dis+202,INF);
	fill(happy,happy+202,0);
	fill(cnum,cnum+202,INF);
	dis[0]=0;cnum[0]=0;//pathnum[0]=1;
	while(1){
		int t=-1,mindis=INF;
		for(int i=0;i<n;i++){
			if(!visited[i]&&dis[i]<mindis)
				t=i;
		}
		if(t==-1)
			break;
		visited[t]=true;
		for(int i=0;i<n;i++){
			if(!visited[i]&&cost[i][t]!=INF){
				if(dis[i]>dis[t]+cost[i][t]){
					pathnum[i]=1;

					dis[i]=dis[t]+cost[i][t];
					path[i]=t;
					happy[i]=happy[t]+cities[i].happ;
					cnum[i]=cnum[t]+1;
				}else if(dis[i]==dis[t]+cost[i][t]){
					pathnum[i]++;
					if(happy[i]<happy[t]+cities[i].happ){
						path[i]=t;
						happy[i]=happy[t]+cities[i].happ;
						cnum[i]=cnum[t]+1;
					}else if(happy[i]==happy[t]+cities[i].happ){
						if(cnum[i]>cnum[t]+1){
							path[i]=t;
							cnum[i]=cnum[t]+1;
						}
					
					}

				}

			}

		}






	}//while

	printf("%d %d %d %d\n",pathnum[rom],dis[rom],happy[rom],happy[rom]/cnum[rom]);
	printf("%s",cities[0].name);
	printp(rom);
	

	getchar();
	getchar();
	return 0;
}