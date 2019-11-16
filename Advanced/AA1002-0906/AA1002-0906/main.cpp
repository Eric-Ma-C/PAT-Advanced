#include<stdio.h>
#include<map>
#include<vector>
using namespace std;


int main(){
	int k1,k2;
	scanf("%d",&k1);
	vector<pair<int,double> > p1;
	for(int i=0;i<k1;i++){
		int e;double a;
		scanf("%d %lf",&e,&a);
		p1.push_back(make_pair(e,a));
	}
	scanf("%d",&k2);
	vector<pair<int,double> > p2;
	for(int i=0;i<k2;i++){
		int e;double a;
		scanf("%d %lf",&e,&a);
		p2.push_back(make_pair(e,a));
	}
	int i1=0,i2=0;
	vector<pair<int,double> > ans;
	while(i1<k1&&i2<k2){
		if(p1[i1].first==p2[i2].first){
			double tmp=p1[i1].second+p2[i2].second;
			if(tmp!=0){
				ans.push_back(make_pair(p1[i1].first,tmp));
			}
			i1++;i2++;
		}else if(p1[i1].first>p2[i2].first){
			ans.push_back(p1[i1]);
			i1++;
		}else if(p2[i2].first>p1[i1].first){
			ans.push_back(p2[i2]);
			i2++;
		}
	}
	for(;i1<k1;i1++){
		ans.push_back(p1[i1]);
	}
	for(;i2<k2;i2++){
		ans.push_back(p2[i2]);
	}

	printf("%d",ans.size());
	for(int i=0;i<ans.size();i++){
		printf(" %d %.1f",ans[i].first,ans[i].second);
	}


	getchar();
	getchar();
	return 0;
}