#include<stdio.h>
//牛客AC，但pat一个测试点无法通过，注意此case：
//4
//-2 0 0 -1
//输出：0 0 0
int n[10002]={0};
int k;

int main(){
	scanf("%d",&k);
	bool alln=1;
	for(int i=0;i<k;i++){
		scanf("%d",n+i);if(n[i]>=0) alln=0;}

	if(alln){
	printf("%d %d %d",0,n[0],n[k-1]);
	return 0;
	}
	int maxsum=-1,sum=-1;
	int beg=0,end=0;
	
	for(int i=0;i<k;i++){
		sum=0;
		for(int j=i;j<k;j++){
			sum+=n[j];
			if(sum>maxsum){
				maxsum=sum;
				beg=i;end=j;
			}
		}

	}
	
	printf("%d %d %d",maxsum,n[beg],n[end]);

	getchar();
	getchar();
	return 0;
}