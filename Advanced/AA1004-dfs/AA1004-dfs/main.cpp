#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
using namespace std;
struct point{
	int m,n,l;
	point(int _m,int _n,int _l){m=_m;n=_n;l=_l;}
};
bool pic[1286][128][60];
bool visited[1286][128][60]={0};
int t1[6]={1,-1,0,0,0,0};
int t2[6]={0,0,1,-1,0,0};
int t3[6]={0,0,0,0,1,-1};

int M,N,L,T;
int area;
int total=0;
void dfs(point p){
	stack<point> s;
	s.push(p);area++;
	visited[p.m][p.n][p.l]=1;
	while(!s.empty()){
		point t=s.top();
		bool ok=false;
		for(int i=0;i<6;i++){
			int dx=t.m+t1[i];
			int dy=t.n+t2[i];
			int dz=t.l+t3[i];
			if(dx<M&&dx>=0&&dy<N&&dy>=0&&dz<L&&dz>=0
				&&!visited[dx][dy][dz]&&pic[dx][dy][dz]){
					area++;ok=true;
					visited[dx][dy][dz]=1;
					s.push(point(dx,dy,dz));
					break;
			}
		}
		if(!ok){
			s.pop();
		}
	
	}	
}
int main(){
	
	scanf("%d %d %d %d",&M,&N,&L,&T);
	
	int tmp,num=0;
	for(int i=0;i<L;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				scanf("%d",&tmp);
				if(tmp==1) pic[j][k][i]=1;
				else pic[j][k][i]=0;
			}
		}
	}
	for(int i=0;i<L;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				if(!visited[j][k][i]&&pic[j][k][i]){
					area=0;
					dfs(point(j,k,i));
					if(area>=T)
						total+=area;
				}
			}
		}
	}
	printf("%d",total);

	getchar();
	getchar();
	return 0;
}