#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
bool g[505][505];
int degree[505];
bool visited[505]={0};
int n,m;
void dfs(int v){
	visited[v]=true;
	for(int i=1;i<=n;i++){
		if(!visited[i]&&g[v][i]==true)
			dfs(i);
	}
}
int main(){

	scanf("%d %d",&n,&m);
	fill(g[0],g[504]+505,false);
	fill(degree,degree+n,0);

	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		g[a][b]=true;
		g[b][a]=true;
		degree[a]++;
		degree[b]++;
	}

	dfs(1);
	bool connected=true;
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			connected=false;	
			break;
		}
	}
	int odd=0;
	for(int i=1;i<=n;i++){
		if(degree[i]%2==1)
			odd++;
		if(i!=1)printf(" ");
		printf("%d",degree[i]);
	}
	printf("\n");
	if(connected&&odd==0)
		printf("Eulerian");
	else if(connected&&odd==2)
		printf("Semi-Eulerian");
	else
		printf("Non-Eulerian");

	getchar();
	getchar();
	return 0;
}

