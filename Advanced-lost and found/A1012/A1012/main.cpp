#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
//28min
int main(){
	int nc,np;
	scanf("%d",&nc);
	int *lc=(int *)malloc(sizeof(int)*nc);
	for(int i=0;i<nc;i++){
		scanf("%d",lc+i);
	}

	scanf("%d",&np);
	int *lp=(int *)malloc(sizeof(int)*np);
	for(int i=0;i<np;i++){
		scanf("%d",lp+i);
	}

	std::sort(lc,lc+nc);
	std::sort(lp,lp+np);

	int ans=0;
	for(int i=0;lc[i]<0&&lp[i]<0&&i<nc&&i<np;i++){
		ans+=lc[i]*lp[i];
	}
	int ic=nc-1,ip=np-1;
	for(;lc[ic]>0&&lp[ip]>0&&ic>=0&&ip>=0;ic--,ip--){
		ans+=lc[ic]*lp[ip];
	}

	printf("%d",ans);
	getchar();
	getchar();
	return 0;
}