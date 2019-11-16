#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
//60min
int parent[10001];
int visited[10001];

int root(int i){
	while(parent[i]>=0)
		i=parent[i];
	return i;
}
void unionNode(int r1,int r2){
	if(parent[r1]>parent[r2]){
		parent[r2]+=parent[r1];parent[r1]=r2;
	}else{
		parent[r1]+=parent[r2];parent[r2]=r1;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	vector<int> e[10001];
	fill(parent,parent+10000,-1);
	int r1,r2;
	int e1,e2;
	for(int i=0;i<n-1;i++){
		scanf("%d %d",&e1,&e2);
		e[e1].push_back(e2);
		e[e2].push_back(e1);
		r1=root(e1);
		r2=root(e2);
		if(r1!=r2)//构建并查集
			unionNode(r1,r2);
	}
	int count=0;
	for(int i=1;i<=n;i++){
		if(parent[i]<0)
			count++;
	}
	if(count!=1){
		printf("Error: %d components",count);
		return 0;
	}
	int deep=0,tag,l;
	vector<int> roots;
	for(int i=1;i<=n;i++){//分别求deep
		if(e[i].size()>1)//必存在度为一的顶点，最深树根必在其中
			continue;

		queue<int> level;
		tag=i;l=0;level.push(i);
		fill(visited,visited+10000,false);
		visited[i]=true;
		while(!level.empty()){
			int t=level.front();
			level.pop();
			for(auto it=e[t].begin();it!=e[t].end();it++){
				if(!visited[*it]){//未访问邻接边入队
					level.push(*it);
					visited[*it]=true;
				}
			}
			if(t==tag&&!level.empty()){
				l++;tag=level.back();
			}
		}//while
		if(l>deep){
			deep=l;roots.clear();roots.push_back(i);
		}else if(l==deep){
			roots.push_back(i);
		}
	}

	sort(roots.begin(),roots.end());

	for(int i=0;i<roots.size();i++){
		printf("%d\n",roots[i]);
	}
	getchar();
	getchar();
	return 0;
}