#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//80min
int n,lmax;

vector<int> follower[1001];

bool visited[1001];
int level(int v){
	fill(visited,visited+1001,false);
	int num=0,lev=0,newlev=v;bool settag=false;
	queue<int> q;q.push(v);visited[v]=true;
	while(!q.empty()){
		int t=q.front();
		q.pop();

		if(t==newlev){
			lev++;settag=true;
			if(lev>lmax+1)
				break;
		}
		num++;
		for(int i=0;i<follower[t].size();i++){
			if(!visited[follower[t][i]]){
				visited[follower[t][i]]=true;
				if(settag){settag=false;newlev=follower[t][i];}
				q.push(follower[t][i]);
			}
		}

	}
	return num-1;
}
int main(){
	scanf("%d %d",&n,&lmax);
	for(int i=0;i<n;i++){
		int m;
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			int t;
			scanf("%d",&t);
			//follow[i+1].push_back(t);
			follower[t].push_back(i+1);
		}
	}
	int qnum;
	scanf("%d",&qnum);
	for(int j=0;j<qnum;j++){
		int t;
		scanf("%d",&t);
		//q.push_back(t);
		int num=level(t);
		printf("%d\n",num);
	}
	getchar();
	getchar();
	return 0;
}