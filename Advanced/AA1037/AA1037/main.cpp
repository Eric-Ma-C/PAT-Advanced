#include<stdio.h>

int c[5000]={0};

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int t;
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		c[t]++;
	}
	for(int i=1;i<505;i++){
		if(m-i<=0)break;
		if(c[i]>0){
			c[i]--;
			if(c[m-i]>0){
				printf("%d %d",i,m-i);
				return 0;
			}
		}
	}
	printf("No Solution");
	getchar();
	getchar();
	return 0;
}