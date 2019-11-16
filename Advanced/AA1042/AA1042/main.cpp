#include<stdio.h>
#include<vector>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;
typedef struct ans{
	int id;
	string cmpstr;
}ans;
int w[105];int N,M,S;
vector<int> node[105];
vector<int> path[105];
vector<int> tmp;
void dfs(int v){
	tmp.push_back(w[v]);
	if(node[v].size()==0){
		int sum=0;
		for(int i=0;i<tmp.size();i++)
			sum+=tmp[i];
		if(sum==S){
			path[v].insert(path[v].begin(),tmp.begin(),tmp.end());
		}
	}
	for(int i=0;i<node[v].size();i++){
		dfs(node[v][i]);
	}
	tmp.pop_back();
}
bool cmp(ans &a1,ans &a2){
	return a1.cmpstr>a2.cmpstr;
}
int main(){
	scanf("%d %d %d",&N,&M,&S);
	for(int i=0;i<N;i++)
		scanf("%d",w+i);

	for(int i=0;i<M;i++){
		int nl,k;
		scanf("%d %d",&nl,&k);
		for(int j=0;j<k;j++){
			int t;
			scanf("%d",&t);
			node[nl].push_back(t);
		}
	}

	dfs(0);
	vector<ans> al;
	for(int i=0;i<N;i++){
		if(path[i].size()>0){
			string tmps;
			for(int j=0;j<path[i].size();j++){
				stringstream stream;
				stream << path[i][j];
				tmps+=stream.str();
			}
			ans a;a.id=i;a.cmpstr=tmps;
			al.push_back(a);
		}
	}
	sort(al.begin(),al.end(),cmp);

	for(int i=0;i<al.size();i++){
		printf("%d",path[al[i].id][0]);
		for(int j=1;j<path[al[i].id].size();j++)
			printf(" %d",path[al[i].id][j]);
		printf("\n");
	}

	getchar();
	getchar();
	return 0;
}