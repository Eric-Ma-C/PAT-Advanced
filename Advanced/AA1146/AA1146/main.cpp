#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

bool g[1005][1005]={0};
bool t[1005][1005];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);

		g[a][b]=true;
	}
	int k;
	vector<int> ans;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		memcpy(t,g,sizeof(bool)*1005*1005);
		int tmp[1005];
		for(int j=0;j<n;j++){
			scanf("%d",tmp+j);
		}
		bool ok=true;
		for(int j=0;j<n;j++){
			int cur=tmp[j];
			for(int v=1;v<=n;v++){
				if(t[v][cur]){
					ok=false;break;
				}
			}
			if(!ok)break;
			for(int v=1;v<=n;v++){
				t[cur][v]=false;
			}
		}
		if(!ok)
			ans.push_back(i);
	}
	for(int i=0;i<ans.size();i++){
		if(i!=0)printf(" ");
		printf("%d",ans[i]);
	}
	getchar();
	getchar();
	return 0;

}