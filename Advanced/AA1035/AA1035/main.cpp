#include<stdio.h>
#include<math.h>
int d[100005];
int main(){
	int n,m;int all=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",d+i);all+=d[i];
	}

	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int e1,e2;
		scanf("%d %d",&e1,&e2);
		int dis=0;
		if(e2<e1){
			int t=e2;
			e2=e1;e1=t;
		}
		for(int j=e1;j<e2;j++){
			dis+=d[j];
		}
		if(dis>all/2)dis=all-dis;

		printf("%d\n",dis);

	}

	getchar();
	getchar();
	return 0;
}