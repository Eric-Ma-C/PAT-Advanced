#include<stdio.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef struct stu{
	int gp,gm,gf,g;
	string name;
}stu;
map<string,stu> l;
bool cmp(stu s1,stu s2){
	if(s1.g!=s2.g)
		return s1.g>s2.g;
	return s1.name<s2.name;
}
int main(){
	int p,m,n;
	scanf("%d%d%d",&p,&m,&n);
	char na[30];int g;
	for(int i=0;i<p;i++){
		scanf("%s %d",na,&g);
		string s(na);
		if(l.find(s)==l.end()){
			stu st;st.name=s;st.gf=-1;st.gm=-1;st.gp=-1;
			l[s]=st;
		}
		l[s].gp=g;
	}
	for(int i=0;i<m;i++){
		scanf("%s %d",na,&g);
		string s(na);
		if(l.find(s)==l.end()){
			stu st;st.name=s;st.gf=-1;st.gm=-1;st.gp=-1;
			l[s]=st;
		}
		l[s].gm=g;
	}
	for(int i=0;i<n;i++){
		scanf("%s %d",na,&g);
		string s(na);
		if(l.find(s)==l.end()){
			stu st;st.name=s;st.gf=-1;st.gm=-1;st.gp=-1;
			l[s]=st;
		}
		l[s].gf=g;
	}

	vector<stu> ans;
	for(auto it=l.begin();it!=l.end();it++){
		if(it->second.gp<200)
			continue;
		//int g=0;
		if(it->second.gm>it->second.gf)
			it->second.g=floor(it->second.gm*0.4+it->second.gf*0.6+0.5);
		else
			it->second.g=it->second.gf;
		if(it->second.g>=60)
			ans.push_back(it->second);
	}
	sort(ans.begin(),ans.end(),cmp);
	for(int i=0;i<ans.size();i++){
		printf("%s %d %d %d %d\n",ans[i].name.c_str(),ans[i].gp,ans[i].gm,ans[i].gf,ans[i].g);
	}
	getchar();
	getchar();
	return 0;

}