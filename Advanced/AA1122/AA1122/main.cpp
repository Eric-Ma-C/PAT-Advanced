#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

bool g[205][205]={0};
bool visited[205];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		g[v1][v2]=true;
		g[v2][v1]=true;
	}
	int k,t;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&t);
		int tmp;
		vector<int> cyc;
		fill(visited,visited+n+1,false);
		bool ok=true;
		for(int j=0;j<t;j++){
			scanf("%d",&tmp);
			if(j>0){
				if(g[tmp][cyc.back()]==false)
					ok=false;
			}
			cyc.push_back(tmp);
			visited[tmp]=true;
		}
		if(cyc.size()!=n+1||cyc.front()!=cyc.back())
			ok=false;
		if(ok){
			for(int i=1;i<=n;i++){
				if(!visited[i]){
					ok=false;
					break;
				}
			}
		}
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	getchar();
	getchar();
	return 0;
}

