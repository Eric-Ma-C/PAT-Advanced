#include<stdio.h>

int d[100001][2]={0};
int school[100001][2]={0};

int main(){

	int n;
	scanf("%d",&n);

	
	for(int i=0;i<n;i++){
		scanf("%d %d",d[i],d[i]+1);

		school[d[i][0]][1]+=d[i][1];
	}
	int max=0;int maxI=0;
	for(int j=1;j<100001;j++){
		if(max<school[j][1]){
		max=school[j][1];maxI=j;}
	}

	printf("%d %d",maxI,max);


getchar();
getchar();

return 0;}