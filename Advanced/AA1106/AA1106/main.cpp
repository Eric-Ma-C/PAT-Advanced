#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> ret;
int par[100005];
int cache[100005];

int getlen(int t){
	if(cache[t]!=-1){
		return cache[t];
	}
	if(par[t]==-1)
		return 0;

	return cache[t]=getlen(par[t])+1;
}
int main(){
	int n;double p,r;
	scanf("%d%lf%lf",&n,&p,&r);

	fill(par,par+n,-1);
	fill(cache,cache+n,-1);
	for(int i=0;i<n;i++){
		int t,tmp;
		scanf("%d",&t);
		if(t==0)
			ret.push_back(i);
		for(int j=0;j<t;j++){
			scanf("%d",&tmp);
			par[tmp]=i;
		}
	}
	int count=0,min=0x3fffffff;
	for(int i=0;i<ret.size();i++){
		int t=ret[i];
		int len=getlen(t);
		
		if(len<min){
			min=len;count=1;
		}else if(len==min){
			count++;
		}

	}

	double pri=p*pow(1.0+r/100.0,min);
	printf("%.4f %d",pri,count);


	getchar();
	getchar();
	return 0;
}