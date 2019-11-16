#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<algorithm>
using namespace std;
#define NUM 2005

int main(){
	int k,n;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int n;
		scanf("%d",&n);

		int t;
		bool lt[NUM]={0};
		bool rt[NUM]={0};
		bool row[NUM]={0};

		for(int j=0;j<n;j++){
			scanf("%d",&t);
			row[t]=true;
			lt[j+t]=true;
			rt[j+1+n-t]=true;
		}
		bool ok=true;
		for(int j=1;j<=n;j++){
			if(!row[j]){ok=false;break;}
		}
		int count=0;
		for(int j=1;j<=n*2-1;j++){
			if(lt[j])count++;
		}
		if(count!=n)ok=false;
		count=0;
		for(int j=1;j<=n*2-1;j++){
			if(rt[j])count++;
		}
		if(count!=n)ok=false;

		if(ok)printf("YES\n");
		else printf("NO\n");
	}

	getchar();
	getchar();
	return 0;
}

