#include<stdio.h>
#include<map>
#include<math.h>
using namespace std;
//49min
int main(){
	int n1,n2;
	scanf("%d",&n1);
	map<int,double> p1,p2,p;int ti;double tf;
	for(int i=0;i<n1;i++){
		scanf("%d %lf",&ti,&tf);
		if(p1.find(ti)==p1.end()) p1[ti]=tf;
		else p1[ti]+=tf;
	}
	scanf("%d",&n2);
	for(int i=0;i<n2;i++){
		scanf("%d %lf",&ti,&tf);
		if(p2.find(ti)==p2.end()) p2[ti]=tf;
		else p2[ti]+=tf;
	}

	for(auto it1=p1.begin();it1!=p1.end();it1++){
		for(auto it2=p2.begin();it2!=p2.end();it2++){
			ti=it1->first+it2->first;
			tf=it1->second*it2->second;
			if(p.find(ti)==p.end()){
				p[ti]=tf;
			}else{
				p[ti]+=tf;
			}
			if(p[ti]<0.0001&&p[ti]>-0.0001)
				p.erase(ti);
		}
	}
	int len=p.size();
	printf("%d",len);
	if(len==0)
		return 0;
	auto it=p.end();it--;
	for(;len>0;it--,len--){
		double d=it->second;
		if(d>0)
			d+=1e-8;
		else
			d-=1e-8;
		printf(" %d %.1lf",it->first,d);
	}
	getchar();
	getchar();
	return 0;
}