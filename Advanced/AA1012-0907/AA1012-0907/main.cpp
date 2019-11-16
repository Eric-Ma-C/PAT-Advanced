#include<stdio.h>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct stu{
	string name;
	int a,c,m,e;
	int bestr;
	char best;

}stu;
bool cmpa(stu s1,stu s2){
	return s1.a>s2.a;
}
bool cmpc(stu s1,stu s2){
	return s1.c>s2.c;
}
bool cmpm(stu s1,stu s2){
	return s1.m>s2.m;
}
bool cmpe(stu s1,stu s2){
	return s1.e>s2.e;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<stu> l;
	for(int i=0;i<n;i++){
		char na[10];int c,m,e;
		scanf("%s%d%d%d",na,&c,&m,&e);
		stu s;s.name=string(na);
		s.a=(c+m+e)/3;s.c=c;s.m=m;s.e=e;
		l.push_back(s);
	}
	sort(l.begin(),l.end(),cmpa);
	int rank=1;l[0].bestr=rank;l[0].best='A';
	for(int i=1;i<l.size();i++){
		if(l[i].a!=l[i-1].a)
			rank=i+1;
		l[i].bestr=rank;
		l[i].best='A';
	}
	sort(l.begin(),l.end(),cmpc);
	rank=1;
	if(l[0].bestr>rank){
		l[0].bestr=rank;l[0].best='C';
	}
	for(int i=1;i<l.size();i++){
		if(l[i].c!=l[i-1].c)
			rank=i+1;
		if(l[i].bestr>rank){
			l[i].bestr=rank;l[i].best='C';
		}
	}
	sort(l.begin(),l.end(),cmpm);
	rank=1;
	if(l[0].bestr>rank){
		l[0].bestr=rank;l[0].best='M';
	}
	for(int i=1;i<l.size();i++){
		if(l[i].m!=l[i-1].m)
			rank=i+1;
		if(l[i].bestr>rank){
			l[i].bestr=rank;l[i].best='M';
		}
	}
	sort(l.begin(),l.end(),cmpe);
	rank=1;
	if(l[0].bestr>rank){
		l[0].bestr=rank;l[0].best='E';
	}
	for(int i=1;i<l.size();i++){
		if(l[i].e!=l[i-1].e)
			rank=i+1;
		if(l[i].bestr>rank){
			l[i].bestr=rank;l[i].best='E';
		}
	}
	map<string,stu> ans;
	for(int i=0;i<l.size();i++){
		ans[l[i].name]=l[i];
	}
	for(int i=0;i<m;i++){
		char na[10];
		scanf("%s",na);
		auto it=ans.find(string(na));
		if(it==ans.end())
			printf("N/A\n");
		else printf("%d %c\n",it->second.bestr,it->second.best);
	}

	getchar();
	getchar();
	return 0;
}

