#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;

typedef struct item{
	int count,id;
	item(int i,int c){this->count=c;this->id=i;}
	friend bool operator < (const item &i1,const item &i2){
		if(i1.count!=i2.count)
			return i1.count>i2.count;
		return i1.id<i2.id;
	}
}item;
int num[50005]={0};
set<item> s;
int main(){
	int k,n;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		
		if(i==0){
			s.insert(item(t,++num[t]));
			continue;
		}
		int c=0;
		printf("%d:",t);
		for(auto it=s.begin();it!=s.end()&&c<k;it++,c++){
			printf(" %d",it->id);
		}
		printf("\n");
	
		auto it=s.find(item(t,num[t]));
		if(it!=s.end()){
			s.erase(it);
		}
			
		s.insert(item(t,++num[t]));
	}

	getchar();
	getchar();
	return 0;
}

