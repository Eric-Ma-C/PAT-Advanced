#include<stdio.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

typedef struct school{
	string name;
	int rank,tws,ns;
	int sb,sa,st;
}school;

map<string,school> l;
bool cmp(school s1,school s2){
	if(s1.tws!=s2.tws)
		return s1.tws>s2.tws;
	else{
		if(s1.ns!=s2.ns)
			return s1.ns<s2.ns;
		else
			return s1.name<s2.name;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char id[9],sch[9];int sc;
		scanf("%s %d %s",id,&sc,sch);
		string s(sch);
		transform(s.begin(),s.end(),s.begin(),::tolower);
		if(l.find(s)==l.end()){
			school sl;sl.name=s;sl.ns=0;sl.sb=sl.sa=sl.st=0;
			l[s]=sl;
		}
		if(id[0]=='B'){
			l[s].sb+=sc;
		}else if(id[0]=='A'){
			l[s].sa+=sc;
		}else{
			l[s].st+=sc;
		}
		l[s].ns++;

	}
	vector<school> ans;
	for(auto it=l.begin();it!=l.end();it++){
		it->second.tws=it->second.sb/1.5+it->second.sa+it->second.st*1.5;
		ans.push_back(it->second);
	}
	sort(ans.begin(),ans.end(),cmp);
	printf("%d\n",ans.size());
	int rank=1,tw=-1;
	for(int i=0;i<ans.size();i++){
		if(tw!=ans[i].tws){
			rank=i+1;
			tw=ans[i].tws;
		}
		ans[i].rank=rank;
		printf("%d %s %d %d\n",ans[i].rank,ans[i].name.c_str(),ans[i].tws,ans[i].ns);
	}

	getchar();
	getchar();
	return 0;

}