#include<stdio.h>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
#define INF 0x3fffff

int g[1020][1020];
int d[1020][1020];
int N,M,K,dmax;

int getindex(char *p){
	int index=0;

	if(p[0]=='G'){
		string st(p+1);
		stringstream stream(st);
		stream>>index;
		index+=N;
	}else{
		string st(p);
		stringstream stream(st);
		stream>>index;
	}
	return index;
}
int main(){
	scanf("%d %d %d %d",&N,&M,&K,&dmax);

	fill(g[0],g[1019]+1020,INF);
	fill(d[0],d[1019]+1020,INF);
	char p1[10],p2[10];int ip1,ip2,dis;
	for(int i=0;i<K;i++){
		scanf("%s %s %d",p1,p2,&dis);
		ip1=getindex(p1);
		ip2=getindex(p2);
		g[ip1][ip2]=dis;
		g[ip2][ip1]=dis;
		d[ip1][ip2]=dis;
		d[ip2][ip1]=dis;
	}

	for(int k=1;k<=N+M;k++){
		for(int i=1;i<=N+M;i++){
			for(int j=1;j<=N+M;j++){
				if(d[i][k]!=INF&&d[k][j]!=INF&&
					d[i][j]>d[i][k]+d[k][j])
					d[i][j]=d[i][k]+d[k][j];
			}
		}
	}
	int ans=-1,minok=0,sumok;
	for(int i=N+1;i<=N+M;i++){
		int sum=0,min=INF;
		int j=1;
		for(;j<=N;j++){
			if(d[i][j]>dmax)
				break;
			else{
				if(d[i][j]<min)
					min=d[i][j];
				sum+=d[i][j];
			}
		}
		if(j>N){//备选
			if(min>minok||(min==minok&&sum<sumok)){//最短距离里面最大的
				minok=min;
				sumok=sum;
				ans=i;
			}
		}
	}
	if(ans==-1)
		printf("No Solution");
	else{
		printf("G%d\n",ans-N);
		printf("%.1f %.1f",minok*1.0,sumok*1.0/N);
	}
	getchar();
	getchar();
	return 0;
}