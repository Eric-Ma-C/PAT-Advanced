#include<stdio.h>
#include<queue>
#include<math.h>
using namespace std;

typedef struct mice{
	int id,w,rank;
	friend bool operator <(mice m1,mice m2){return m1.w<m2.w;}
}mice;
mice m[1000];
vector<mice> list;
int main(){
	int np,ng;
	scanf("%d %d",&np,&ng);
	int t;
	for(int i=0;i<np;i++){
		scanf("%d",&t);
		m[i].w=t;m[i].id=i;
		m[i].rank=1;
	}
	for(int i=0;i<np;i++){
		scanf("%d",&t);
		list.push_back(m[t]);
	}

	vector<mice> next;
	priority_queue<mice> q;
	while(list.size()>1){
		int size=list.size();
		int rank=ceil(size*1.0/ng)+1;

		for(int i=0;i<list.size();i++){
			q.push(list[i]);
			if(i%ng==ng-1){
				next.push_back(q.top());
				q.pop();
				while(!q.empty()){
					m[q.top().id].rank=rank;
					q.pop();
				}
			}
		}
		if(!q.empty()){
			next.push_back(q.top());
			q.pop();
			while(!q.empty()){
				m[q.top().id].rank=rank;
				q.pop();
			}
		}
		list.clear();
		for(int i=0;i<next.size();i++)
			list.push_back(next[i]);
		next.clear();
	}
	m[list[0].id].rank=1;

	printf("%d",m[0].rank);
	for(int i=1;i<np;i++){
		printf(" %d",m[i].rank);
	}
	getchar();
	getchar();
	return 0;
}