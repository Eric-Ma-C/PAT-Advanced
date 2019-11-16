#include<stdio.h>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;

typedef struct item{
	int count,id;
	friend bool operator < (const item &i1,const item &i2){
		if(i1.count!=i2.count)
			return i1.count<i2.count;
		return i1.id>i2.id;
	}
}item;
//int num[50005]={0};
unordered_map<int,int> num;
int main(){
	int k,n;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		
		if(i==0){
			num[t]=1;
			continue;
		}

		priority_queue<item> q;
		for(auto it=num.begin();it!=num.end();it++){			
			item itm;itm.id=it->first;itm.count=it->second;
				q.push(itm);
		}
		int c=0;
		printf("%d:",t);
		while(!q.empty()&&c<k){
			printf(" %d",q.top().id);
			q.pop();
			c++;
		}
		printf("\n");
		if(num.find(t)==num.end())
			num[t]=0;
		num[t]++;
	}

	getchar();
	getchar();
	return 0;
}

