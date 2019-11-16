#include<stdio.h>
#include<map>
#include<queue>
using namespace std;
typedef struct mice{
	int id,w,rank;
	friend bool operator <(mice m1,mice m2){return m1.w<m2.w;}
}mice;
mice m[1000];
queue<mice> list;
int main(){
	int np,ng;
	scanf("%d %d",&np,&ng);
	int t;
	for(int i=0;i<np;i++){
		scanf("%d",&t);
		m[i].w=t;m[i].id=i;
		m[i].rank=1;
	}
	map<int,int> ori;
	for(int i=0;i<np;i++){
		scanf("%d",&t);
		ori[t]=i;
	}
	for(int i=0;i<np;i++){
		list.push(m[ori[i]]);
	}
	int currank=1,passed=0;
	priority_queue<mice> q;
	while(passed<np-1){
		if(q.size()<ng&&list.front().rank==currank&&!list.empty()){
			q.push(list.front());
			list.pop();
		}else{
			mice win=q.top();
			m[win.id].rank++;
			if(list.front().rank!=currank)
				currank=m[win.id].rank;
			list.push(m[win.id]);
			passed+=q.size()-1;
			while(!q.empty())
				q.pop();
			
		}
	}
	int max=list.front().rank;
	printf("%d",max+1-m[0].rank);
	for(int i=1;i<np;i++){
		printf(" %d",max+1-m[i].rank);
	}
	getchar();
	getchar();
	return 0;
}