#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

bool show[100005]={0};
int main(){
	int n;
	scanf("%d",&n);
	map<int,int> coup;
	for(int i=0;i<n;i++){
		int c1,c2;
		scanf("%d %d",&c1,&c2);
		coup[c1]=c2;
		coup[c2]=c1;
	}
	int m;
	scanf("%d",&m);
	vector<int> guest;
	for(int i=0;i<m;i++){
		int p;
		scanf("%d",&p);
		show[p]=true;
		guest.push_back(p);
	}
	vector<int> ans;
	for(int i=0;i<guest.size();i++){
		auto it=coup.find(guest[i]);
		if(it==coup.end()||(!show[it->second])){
			ans.push_back(guest[i]);
		}
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		if(i!=0)printf(" ");
		printf("%05d",ans[i]);
	}


	getchar();
	getchar();
	return 0;
}

