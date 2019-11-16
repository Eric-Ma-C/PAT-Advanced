#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
//25min
vector<int> node[100];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);

	int id,k;
	for(int i=0;i<m;i++){
		scanf("%d %d",&id,&k);
		int ch;
		while(k--){
			scanf("%d",&ch);
			node[id].push_back(ch);
		}
	}	
	queue<int> q;q.push(1);int last=1,prelast=0;int num=0;bool fir=true;
	while(!q.empty()){
		int t=q.front();q.pop();


		for(auto it=node[t].begin();it!=node[t].end();it++){
			q.push(*it);
			if(it==node[t].end()-1)
				prelast=*it;
		}
		if(node[t].size()==0)
			num++;




		if(t==last){
			if(fir){fir=false;printf("%d",num);}
			else
			printf(" %d",num);
			num=0;
			last=prelast;
		}
	}


	getchar();
	getchar();
	return 0;
}