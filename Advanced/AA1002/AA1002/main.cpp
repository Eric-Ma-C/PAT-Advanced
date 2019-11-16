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

vector<int> tmppath;
int path[202];
int visited[202]={0};
int n,k;
city* cities;
int rom,costmin=INF,happmax=0,num=INF,pathnum=0;
void dfs(int v){
	if(v==rom){
		tmppath.push_back(v);
		int costv=0,happv=0;
		for(int i=1;i<tmppath.size();i++){
			costv+=cost[tmppath[i-1]][tmppath[i]];
			happv+=cities[tmppath[i]].happ;
		}
		if(costv<costmin) pathnum=1;
		else pathnum++;
		if(costv<costmin||(costv==costmin&&happv>happmax)||
			(costv==costmin&&happv==happmax&&tmppath.size()<num)){
				costmin=costv;
				happmax=happv;
				num=tmppath.size();
				fill(path,path+202,-1);
				for(int i=0;i<num;i++)
					path[i]=tmppath[i];
		}
		tmppath.pop_back();
		return;
	}
	visited[v]=true;
	tmppath.push_back(v);
	for(int i=0;i<n;i++){
		if(cost[i][v]!=INF&&!visited[i])
			dfs(i);
	}

	visited[v]=false;
	tmppath.pop_back();
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
	rom=toint[roms];

	dfs(0);

	printf("%d %d %d %d\n",pathnum,costmin,happmax,);
	printf("%s",cities[0].name);
	for(int i=1;i<num;i++){
		printf("->%s",cities[path[i]].name);
	}
	

	getchar();
	getchar();
	return 0;
}