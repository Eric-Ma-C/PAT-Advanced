#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
double weight[1005];
vector<pair<int,double> > price;
bool cmp(pair<int,double> p1,pair<int,double> p2){
	return p1.second/weight[p1.first]>p2.second/weight[p2.first];
}
int main(){
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=0;i<n;i++)
		scanf("%lf",weight+i);
	for(int i=0;i<n;i++){
		double p;
		scanf("%lf",&p);
		price.push_back(make_pair(i,p));
	}
	sort(price.begin(),price.end(),cmp);
	double amount=0.0;int i=0;double w=d;
	while(w>0&&i<price.size()){
		if(weight[price[i].first]<w){
			amount+=price[i].second;
		}else{
			amount+=price[i].second*w/weight[price[i].first];
			break;
		}
		w-=weight[price[i].first];
		i++;
	}
	printf("%.2f",amount);
	getchar();
	getchar();
	return 0;
}