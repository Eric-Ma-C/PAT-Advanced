#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int m,n;
	scanf("%d %d",&m,&n);

	int max=1000000;int num=0;
	bool *prime=(bool*)malloc(sizeof(bool)*max);
	memset(prime,-1,sizeof(bool)*max);
	//prime[2]=true;
	for(int i=2;i<max;i++){
		if(prime[i]){
			num++;
			if(num>=m&&num<n){
				if((num-m)%10==9)	
					printf("%d\n",i);
				else
					printf("%d ",i);
			}	
			
			if(num>=n){
				printf("%d",i);
				break;
			}
			for(int j=i+i;j<max;j+=i){
				prime[j]=false;
			}
		}
	}

	/*for(int i=0;i<max;i++){
		if()
	}*/
	getchar();
	getchar();
	return 0;
}