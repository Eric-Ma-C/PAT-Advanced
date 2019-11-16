#include<stdio.h>
#include<unordered_set>
#include<algorithm>
using namespace std;
int m,n;
int pre[10005];
unordered_set<int> has;//判断有没有a,b

int main(){
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d",pre+i);
		has.insert(pre[i]);
	}
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		int j=0;
		for(;j<n;j++){//在先序序列中找a,b可能的最近公共祖先
			if((pre[j]>=a&&pre[j]<=b)||(pre[j]<=a&&pre[j]>=b))
				break;
		}
		int lca=pre[j];
		bool hasa=has.find(a)!=has.end()?true:false;
		bool hasb=has.find(b)!=has.end()?true:false;

		if(!hasa&&!hasb){
			printf("ERROR: %d and %d are not found.\n",a,b);
		}else if(!hasa){
			printf("ERROR: %d is not found.\n",a);
		}else if(!hasb){
			printf("ERROR: %d is not found.\n",b);
		}else {
			if(lca==a)
				printf("%d is an ancestor of %d.\n",a,b);
			else if(lca==b)
				printf("%d is an ancestor of %d.\n",b,a);
			else
				printf("LCA of %d and %d is %d.\n",a,b,lca);
		}
	}
	getchar();
	getchar();
	return 0;
}

