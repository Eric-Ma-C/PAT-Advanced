#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
//35min
typedef long long ll;
vector<ll> num;
int findi(ll v){
	int l=0,h=num.size();
	int i=(l+h)/2;
	while(num[i]!=v&&l!=i){
		if(num[i]<v)
			l=i;
		else if(num[i]>v)
			h=i;
		else return i;
		i=(l+h)/2;
	}
	return i;
}
int main(){
	int n,p;
	scanf("%d %d",&n,&p);
	for(int i=0;i<n;i++){
		ll t;
		scanf("%lld",&t);
		num.push_back(t);
	}
	sort(num.begin(),num.end());
	int max=0;
	for(int i=0;i<num.size();i++){
		ll tmp=num[i]*p;
		/*int j=num.size()-1;
		for(;num[j]>tmp&&j>i;j--)
		;*/
		int j=findi(tmp);
		int c=j-i+1;
		if(c>max)
			max=c;
		if(j==num.size()-1)
			break;
	}
	printf("%d",max);
	getchar();
	getchar();
	return 0;
}

