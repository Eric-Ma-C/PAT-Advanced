#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
//60min
set<int> v[51];
double t[50][50]={0};
double getS(int s1,int s2){
	if(t[s2][s1]>0)
		return t[s2][s1];

	int same=0,diff=0;
	auto it2=v[s2].begin(),it1=v[s1].begin();
	for(;it2!=v[s2].end()&&it1!=v[s1].end();){
		if(*it1>*it2)
			it2++;
		else if(*it2>*it1)
			it1++;
		else
		{same++;it1++;it2++;}
	}
	diff=v[s1].size()+v[s2].size()-same;
	t[s1][s2]=t[s2][s1]=same*100.0/diff;
	return t[s2][s1];

}
int main(){
	int n;
	scanf("%d",&n);
	fill(t[0],t[49]+50,-1);
	for(int i=1;i<=n;i++){
		int m;
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			int t;
			scanf("%d",&t);
			v[i].insert(t);
		}
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		double f=getS(t1,t2);
		printf("%.1f%%\n",f);
	}

	getchar();
	getchar();
	return 0;}