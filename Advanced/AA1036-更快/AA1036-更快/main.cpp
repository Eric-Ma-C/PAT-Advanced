#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string> course[2502];

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		char name[5];int num;
		scanf("%s %d",name,&num);
		int a;string na(name);
		for(int j=0;j<num;j++){
			scanf("%d",&a);
			course[a].push_back(na);
		}
	}
	for(int i=1;i<=k;i++){
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin(),course[i].end());
		for(int j=0;j<course[i].size();j++)
			printf("%s\n",course[i][j].c_str());
	}

	getchar();
	getchar();
	return 0;
}