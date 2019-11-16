#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

vector<int> tree[105];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int id,k,tmp;
		scanf("%d %d",&id,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&tmp);
			tree[id].push_back(tmp);
		}
	}
	queue<int> q;
	q.push(1);
	int begin=1,leaf=0;bool pre=false,first=true;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		if(t==begin){
			if(t!=1){
				if(!first)printf(" ");
				else first=false;
				printf("%d",leaf);
			}leaf=0;pre=true;
		}
		if(tree[t].size()==0)
			leaf++;
		for(int i=0;i<tree[t].size();i++){
			if(pre){
				begin=tree[t][i];
				pre=false;
			}
			q.push(tree[t][i]);
		}

	}
	if(n!=1)printf(" ");
	printf("%d",leaf);
	getchar();
	getchar();
	return 0;
}

