#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int *len,*pre,root;
int getlen(int i){
	if(len[i]!=-1)
		return len[i];
	if(i==root)
		return len[i]=0;

	return len[i]=getlen(pre[i])+1;
}
int main(){
	int n;
	double p,r;
	scanf("%d %lf %lf",&n,&p,&r);
	pre=(int *)malloc(sizeof(int)*n);
	len=(int*)malloc(sizeof(int)*n);

	for(int i=0;i<n;i++){
		scanf("%d",pre+i);
		if(pre[i]==-1) root=i;
	}
	fill(len,len+n,-1);
	for(int i=0;i<n;i++){
		getlen(i);
	}
	int maxlen=0,num=0;
	for(int i=0;i<n;i++){
		if(len[i]>maxlen){
			maxlen=len[i];
			num=1;
		}else if(len[i]==maxlen)
			num++;
	}
	double pmax=p;
	for(int i=0;i<maxlen;i++)
		pmax=pmax*(1+r/100.0f);

	printf("%.2f %d",pmax,num);
	getchar();
	getchar();
	return 0;
}