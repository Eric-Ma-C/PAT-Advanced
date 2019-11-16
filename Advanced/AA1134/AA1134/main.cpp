#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int e[10005][2];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		e[i][0]=v1;
		e[i][1]=v2;
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int nv;
		scanf("%d",&nv);
		set<int> se;
		for(int j=0;j<nv;j++){
			int t;
			scanf("%d",&t);
			se.insert(t);
		}
		bool ok=true;
		for(int j=0;j<m;j++){
			if(se.find(e[j][0])==se.end()&&se.find(e[j][1])==se.end()){
				ok=false;break;
			}
		}
		if(ok)printf("Yes\n");
		else printf("No\n");

	}

	getchar();
	getchar();
	return 0;
}