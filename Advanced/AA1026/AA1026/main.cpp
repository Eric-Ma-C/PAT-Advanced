#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 10005
int v[MAX];
int dp[MAX][105]={0};
bool choose[MAX][105]={0};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++)
		scanf("%d",v+i);

	sort(v+1,v+N+1,cmp);//从大到小，使选择结果满足字典序
	for(int i=1;i<=N;i++){
		for(int m=v[i];m<=M;m++){
			int a=dp[i-1][m];//状态转移方程
			int b=dp[i-1][m-v[i]]+v[i];
			if(b>=a){
				choose[i][m]=true;//相等时也选择i号硬币，保证结果字符串更小
				dp[i][m]=b;
			}else{
				dp[i][m]=a;
			}
		}
	}
	if(dp[N][M]==M){//有解
		vector<int> out;int i=N,m=M;
		while(i>0){
			if(choose[i][m])//回溯路径，找到每个节点状态
			{out.push_back(i);m-=v[i];}
			i--;
		}
		printf("%d",v[out[0]]);
		for(int i=1;i<out.size();i++){
			printf(" %d",v[out[i]]);
		}
	}else{
		printf("No Solution");
	}

	getchar();
	getchar();
	return 0;
}