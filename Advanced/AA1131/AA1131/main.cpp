#include<stdio.h>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 0x3fffffff
#define NUM 10005
typedef struct station{
	int id,k;
	int line[5];
	//bool isTransfer; 
}station; 
map<int,station> sta;
//station sta[NUM];
int g[NUM][NUM];
bool hasid[NUM]={0};
vector<int> path[NUM];
bool visited[NUM];
int dis[NUM];

//bool bfs(int begin,int end){
//	int count=0;
//	visited[begin]=true;
//	queue<p> q;
//	q.push(p(begin,-1));
//	int parent=begin;
//	while(!q.empty()){
//		p tmp=q.front();
//		q.pop();
//
//		path[tmp.id]=id;
//		if(id==end)
//			break;
//
//		for(int i=0;i<NUM;i++){
//		if(hasid[i]&&!visited[i]&&g[i][id]){
//			visited[i]=true;
//			q.push(i);
//		}
//	}
//	}
//} 

void dijkstra(int begin){
	fill(dis,dis+NUM,INF);
	fill(visited,visited+NUM,false);
	dis[begin]=0;
	//bfs(a,b);
	while(1){
		int t=-1,min=INF;
		for(int i=0;i<NUM;i++){
			if(hasid[i]&&!visited[i]&&dis[i]<min){
				min=dis[i];t=i;
			}
		}
		if(t==-1)
			break;
		visited[t]=true;
		for(int i=0;i<NUM;i++){
			if(hasid[i]&&!visited[i]&&g[i][t]!=INF&&dis[i]>=dis[t]+1){
				dis[i]=dis[t]+1;
				path[i].push_back(t);
			}
		}

	}//while
}
vector<int> tmpp,p;
int transfer=0,mintran=INF;
void dfs(int v){
	tmpp.push_back(v);

	if(path[v].size()==0){
		if(mintran>transfer){
			p=tmpp;mintran=transfer;
		}
		return;
	}
	if(sta[v].k>1)
		transfer++;
	for(int i=0;i<path[v].size();i++)
		dfs(path[v][i]);
}
vector<int> getpath(int end){
	p.clear();
	tmpp.clear();
	transfer=0;
	mintran=INF;
	dfs(end);
	return p;
}


int main(){
	int n;
	scanf("%d",&n);
	fill(g[0],g[NUM-1]+NUM,INF);
	for(int i=1;i<=n;i++){
		int m;
		scanf("%d",&m);
		int last;
		for(int j=0;j<m;j++){
			int t;
			scanf("%d",&t);
			hasid[t]=true;
			if(sta.find(t)==sta.end()){
				station st;st.id=t;st.k=0;
				sta[t]=st;
			}
			sta[t].id=t;
			if(sta[t].line[sta[t].k-1]!=i)
				sta[t].line[sta[t].k++]=i;

			if(j!=0){
				g[t][last]=g[last][t]=i;
			}
			last=t;
		}
	}

	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int a,b;
		scanf("%d %d",&a,&b);

		dijkstra(a);
		vector<int> p;
		p=getpath(b);

		printf("%d\n",dis[b]);int line=-1;
		int beg=-1,end;
		for(int i=p.size()-2;i>=0;i--){
			end=p[i];
			if(g[p[i+1]][p[i]]!=line){//新line
				if(line!=-1){//输出上一条线路
					printf("Take Line#%d from %04d to %04d.\n",line,beg,end);
				}
				beg=p[i+1];
				line=g[p[i+1]][p[i]];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n",line,beg,end);
	}



	getchar();
	getchar();
	return 0;
}