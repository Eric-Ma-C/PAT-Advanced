#include<stdio.h>
#include<algorithm>
#include<map>
#define MAX 100000
int prime[MAX]={0};
bool t[MAX];int num=0;

int main(){
	long long n,m;
	scanf("%lld",&m);
	n=m;
	if(n==1){printf("1=1");return 0;}
	std::fill(t,t+MAX,true);
	for(int i=2;i<MAX;i++){
		if(t[i]){
			prime[num++]=i;
			for(int k=i+i;k<MAX;k+=i)
				t[k]=false;
		}
	}
	std::map<long long,int> fac;
	int i=0;

	for(int i=0;i<num&&n>1;i++){
		if(n%prime[i]==0){
			fac[prime[i]]=1;n/=prime[i];
			while(n%prime[i]==0&&n>0){
				fac[prime[i]]++;
				n/=prime[i];
			}
		}
	}
	if(n>1){
		fac[n]=1;//最多一个大于N^0.5的质因子
	}
	printf("%lld=",m);
	
	
	for(auto it=fac.begin();it!=fac.end();it++){
		if(it!=fac.begin())
			printf("*");
		printf("%lld",it->first);
		if(it->second>1)
			printf("^%d",it->second);
	}

	getchar();
	getchar();
	return 0;
}