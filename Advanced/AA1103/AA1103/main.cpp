#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> ans[100000];
vector<int> tmp;
int N,K,P;	
int num=0;
void kpn(int k,int n){
	if(k==1){
		int t=pow(n,1.0/P);
		if((int)pow(t*1.0,P)==n){
			tmp.push_back(t);

			

			ans[num].insert(ans[num].begin(),tmp.begin(),tmp.end());
			tmp.pop_back();
			num++;
		}
		return;
	}
	int min=pow(n*1.0/k,1.0/P);
	int t=pow(min*1.0,P)*k;
	if(t<n)
		min++;
	int max=pow((n-k+1)*1.0,1.0/P);
	if(tmp.size()!=0&&max>tmp.back())
		max=tmp.back();
	for(int i=min;i<=max;i++){
		tmp.push_back(i);
		int nn=n-pow(i*1.0,P);
		kpn(k-1,nn);
		tmp.pop_back();
	}
}
bool cmp(int i1,int i2){
	return i1>i2;
}
bool cmp2(vector<int> v1,vector<int> v2){
	for(int i=0;i<v1.size()&&i<v2.size();i++){
		if(v1[i]!=v2[i])
			return v1[i]>v2[i];
	}
	return false;
}
int main(){
	scanf("%d%d%d",&N,&K,&P);
	kpn(K,N);

	if(num==0){
		printf("Impossible\n");
		return 0;
	}
	for(int i=0;i<num;i++){
		sort(ans[i].begin(),ans[i].end(),cmp);
	}
	sort(ans,ans+num,cmp2);
	int summax=0,ansid=0;
	for(int i=0;i<num;i++){
		int sum=0;
		for(int j=0;j<K;j++)
			sum+=ans[i][j];
		if(sum>summax){
			summax=sum;
			ansid=i;
		}
	}
	printf("%d = ",N);
	for(int i=0;i<ans[ansid].size();i++){
		if(i!=0)printf(" + ");
		printf("%d^%d",ans[ansid][i],P);
	}

	getchar();
	getchar();
	return 0;
}
//390 21 2