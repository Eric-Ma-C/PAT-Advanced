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

	sort(v+1,v+N+1,cmp);//�Ӵ�С��ʹѡ���������ֵ���
	for(int i=1;i<=N;i++){
		for(int m=v[i];m<=M;m++){
			int a=dp[i-1][m];//״̬ת�Ʒ���
			int b=dp[i-1][m-v[i]]+v[i];
			if(b>=a){
				choose[i][m]=true;//���ʱҲѡ��i��Ӳ�ң���֤����ַ�����С
				dp[i][m]=b;
			}else{
				dp[i][m]=a;
			}
		}
	}
	if(dp[N][M]==M){//�н�
		vector<int> out;int i=N,m=M;
		while(i>0){
			if(choose[i][m])//����·�����ҵ�ÿ���ڵ�״̬
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