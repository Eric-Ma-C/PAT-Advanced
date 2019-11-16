#include<stdio.h>
#include<set>
#include<string>
using namespace std;
set<string> course[2502];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		char name[5];int num;
		scanf("%s %d",name,&num);
		int a;string ns(name);
		for(int j=0;j<num;j++){
			scanf("%d",&a);
			course[a].insert(ns);
		}
	}
	for(int i=1;i<=k;i++){
		printf("%d %d\n",i,course[i].size());
		for(auto it=course[i].begin();it!=course[i].end();it++)
			printf("%s\n",(*it).c_str());
	}

	getchar();
	getchar();
	return 0;
}