#include<stdio.h>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

bool g[305][305]={0};//关系邻接矩阵
map<string,int> id;//题目ID转邻接矩阵下标
map<int,string> name;//矩阵下标转题目ID
bool cmp(pair<string,string> p1,pair<string,string> p2){
	if(p1.first!=p2.first)
		return p1.first<p2.first;
	return p1.second<p2.second;
}
bool isMale(string s){
	if(s[0]!='-')
		return true;
	return false;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int count=0;
	for(int i=0;i<m;i++){
		char aa[8],bb[8];
		scanf("%s %s",aa,bb);//string应对-0000情况
		string a(aa),b(bb);

		if(id.find(a)==id.end()){
			name[count]=a;
			id[a]=count++;
		}
		if(id.find(b)==id.end()){
			name[count]=b;
			id[b]=count++;
		}
		g[id[a]][id[b]]=true;
		g[id[b]][id[a]]=true;
	}
	int k=0;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		char aa[8],bb[8];
		scanf("%s %s",aa,bb);
		string a(aa),b(bb);

		if(id.find(a)==id.end()||id.find(b)==id.end()){
			printf("0\n");
			continue;
		}
		set<int> fa,fb;//friends of a,b
		for(int j=0;j<count;j++){
			if(isMale(a)==isMale(name[j])&&g[id[a]][j]&&name[j]!=b)//防止A,B已经是好友
				fa.insert(j);
			if(isMale(b)==isMale(name[j])&&g[id[b]][j]&&name[j]!=a)
				fb.insert(j);
		}
		vector<pair<string ,string> > ans;
		for(auto it1=fa.begin();it1!=fa.end();it1++){
			for(auto it2=fb.begin();it2!=fb.end();it2++){
				if(g[*it1][*it2]){
					int i1=name[*it1][0]=='-'?1:0;
					string s1=name[*it1].substr(i1);
					int i2=name[*it2][0]=='-'?1:0;
					string s2=name[*it2].substr(i2);

					ans.push_back(make_pair(s1,s2));
				}
			}
		}
		sort(ans.begin(),ans.end(),cmp);
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++){
			printf("%s %s\n",ans[i].first.c_str(),ans[i].second.c_str());
		}
	}

	getchar();
	getchar();
	return 0;

}