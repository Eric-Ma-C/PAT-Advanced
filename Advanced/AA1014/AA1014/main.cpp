#include<stdio.h>
#include<map>
#include<math.h>
using namespace std;
//39min
int n;
double p,r;
int root[100000];
int level[100000]={0};//节点所在层数,优化时间

map<int,int> leaves;//零售商编号，货物数量
int getlevel(int n){
	if(n==0)
		return 0;
	if(level[n]!=0)
		return level[n];

	return level[n]=getlevel(root[n])+1;
}
int main(){
	scanf("%d %lf %lf",&n,&p,&r);
	root[0]=-1;
	int t;
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		if(t>0){
			int ch;
			for(int j=0;j<t;j++){
				scanf("%d",&ch);
				root[ch]=i;
			}
		} 
		if(t==0){
			int num;
			scanf("%d",&num);
			leaves[i]=num;
		}
	}
	int node,num;
	double amount=0;
	for(auto it=leaves.begin();it!=leaves.end();it++){
		node=it->first;num=it->second;
		double tmp,count=0;
		count=getlevel(node);
		tmp=pow(1.0+r/100.0,count);
		amount+=p*tmp*num;
	}

	printf("%.1f",amount);

	getchar();
	getchar();
	return 0;
}