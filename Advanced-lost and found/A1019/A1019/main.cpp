#include<stdio.h>
//63min
int n[10002]={0};
int k;
int sumij(int i,int j){
	int sum=0;
	for(;i<j;i++)
		sum+=n[i];

	return sum;
}
int main(){
	scanf("%d",&k);
	bool alln=1;
	for(int i=0;i<k;i++){
		scanf("%d",n+i);if(n[i]>0) alln=0;}

	if(alln){
	printf("%d %d %d",0,n[0],n[k-1]);
	return 0;
	}
	int sum=0,maxsum=0;int s1=0,s2=0;
	int beg=0,end=0;
	for(int i=0;i<k;i++){
		sum+=n[i];
		s2=i;
		if(sum<=0){
			sum=0;s1=i+1;s2=i+1;
		}else if(sum>maxsum){
			maxsum=sum;beg=s1;end=s2;
		}
		
	}

	
	printf("%d %d %d",maxsum,n[beg],n[end]);


	getchar();
	getchar();
	return 0;
}