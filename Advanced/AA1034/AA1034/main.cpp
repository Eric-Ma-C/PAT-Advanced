#include<stdio.h>
#include<algorithm>
using namespace std;

int order[205];
int maxdp[205]={0};

int a[10005];
int dp[205][10005]={0};
int main(){
	int n,m,l;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",order+i);
	}
	scanf("%d",&l);
	for(int i=1;i<=l;i++){
		scanf("%d",a+i);
	}
	for(int i=1;i<=l;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<=m;i++){
		dp[i][0]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=l;j++){
			int maxdp=max(dp[i-1][j],dp[i][j-1]);
			maxdp=max(dp[i-1][j-1],maxdp);
			if(order[i]==a[j])
				maxdp++;
			dp[i][j]=maxdp;
		}
	}
	printf("%d",dp[m][l]);
	getchar();
	getchar();
	return 0;
}