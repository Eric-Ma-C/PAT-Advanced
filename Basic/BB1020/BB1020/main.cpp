#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
int main(){
	int n,p;
	scanf("%d %d",&n,&p);
	
	int *list=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",list+i);
	}
	std::sort(list,list+n);
	int j=0;
	int max=0;long tmp=0;
	for(int i=0;i<n-max;i++){
		tmp=list[i]*p;
		j=i;
		for(;j<n&&list[j]<=tmp;j++)
			;
		if(j-i>max)
			max=j-i;
	}

	printf("%d",max);
	getchar();
	getchar();
	return 0;
}