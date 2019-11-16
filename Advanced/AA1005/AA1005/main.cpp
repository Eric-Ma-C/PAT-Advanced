#include<stdio.h>
using namespace std;
#include<queue>
//50min

int a[101][101]={0};
int g[101]={0};
int main(){
	int n,m;
	scanf("%d %d",&n,&m);

	int t,num;
	for(int i=0;i<m;i++){
		scanf("%d %d",&t,&num);

		for(int j=1;j<=num;j++){
			scanf("%d",&a[t][j]);
		}
	}
	queue<int> qp;
	queue<int> qch;
	qp.push(1);
	g[1]=1;int gnum=1;
	do{
		gnum++;

		while(!qp.empty()){
			int t=qp.front();
			qp.pop();
			for(int i=1;a[t][i]!=0;i++){
				qch.push(a[t][i]);
				g[gnum]++;
			}
		}

		while(!qch.empty()){
			qp.push(qch.front());
			qch.pop();
		}

	}while(!qp.empty());

	int maxi=1,max=0;
	for(int i=1;i<101;i++){
		if(g[i]>max){
			maxi=i;max=g[i];
		}
	}

	printf("%d %d",max,maxi);



getchar();
getchar();
return 0;
}