#include<stdio.h>
#include<map>
using namespace std;
//15min
int main(){
	int n;
	scanf("%d",&n);
	map<int,pair<int,int>> m;
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		if(m.find(t)==m.end()){
			m[t]=make_pair(i,1);
		}else{
			m[t].second++;
		}
	}
	int min=100000,val=-1;
	for(auto it=m.begin();it!=m.end();it++){
		if(it->second.second==1&&it->second.first<min)
		{min=it->second.first;val=it->first;}
	}
	if(val==-1)printf("None");
	else printf("%d",val);

	getchar();
	getchar();
	return 0;
}