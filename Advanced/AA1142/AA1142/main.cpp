#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

bool g[250][250]={0};
int main(){
	int nv,ne;
	scanf("%d %d",&nv,&ne);
	for(int i=0;i<ne;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		g[a][b]=true;
		g[b][a]=true;
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int k;
		scanf("%d",&k);
		int t;
		vector<int> tmp;
		for(int j=0;j<k;j++){
			scanf("%d",&t);
			tmp.push_back(t);
		}
		int count[250]={0};
		for(int j=0;j<tmp.size();j++){
			int v=tmp[j];
			for(int n=1;n<=nv;n++){
				if(g[v][n]){
					count[n]++;
				}
			}
		}
		bool ok=true;
		for(int j=0;j<tmp.size();j++){
			if(count[tmp[j]]<tmp.size()-1){
				ok=false;break;
			}
		}
		bool ismax=true;
		if(ok){
			for(int n=1;n<=nv;n++){
				if(count[n]==tmp.size()){
					ismax=false;break;
				}
			}
		}
		if(ok){
			if(ismax)printf("Yes\n");
			else printf("Not Maximal\n");
		}else{
			printf("Not a Clique\n");
		}
	}
	getchar();
	getchar();
	return 0;

}