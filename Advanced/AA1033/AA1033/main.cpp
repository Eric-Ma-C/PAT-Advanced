#include<stdio.h>
#include<map>
#include<vector>
using namespace std;

int c[100005];
int sum[100005];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int s=0;sum[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
		sum[i]=s+c[i];
		s=sum[i];
	}
	int dis=0x3fffffff,offset=1; 
	vector<pair<int,int> > ans;
	for(int i=1;i<=n;i++){
		int j=offset;
		for(;j<=n;j++){
			if(sum[j]-sum[i-1]<m){
				offset=j;
				continue;
			}else{
				if(dis>=sum[j]-sum[i-1]-m){
					if(dis>sum[j]-sum[i-1]-m)
						ans.clear();
					ans.push_back(make_pair(i,j));
					dis=sum[j]-sum[i-1]-m;
				}
				break;
			}
		}
	}

	for(int i=0;i<ans.size();i++){
		printf("%d-%d\n",ans[i].first,ans[i].second);
	}
	getchar();
	getchar();
	return 0;
}