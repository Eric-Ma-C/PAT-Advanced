#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	multiset<double> r;
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		r.insert(t);
	}
	while(r.size()>1){
		auto it=r.begin();
		double a=*it;
		it++;
		double b=*it;
		double c=(a+b)/2.0;
		r.erase(r.begin());
		r.erase(r.begin());
		r.insert(c);
	}
	printf("%d",(int)*r.begin());

	getchar();
	getchar();
	return 0;
}

