#include<stdio.h>
#include<math.h>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define INF 0x3fffffff

typedef struct pe{
	int id,fa,ma;
	double sets,area;
	int k;
	vector<int> family;
}pe;
typedef struct fami{
	int id,num;
	double sets,area;
}fami;
int par[10005];
map<int,pe> l;
int root(int v){
	int r=v;
	for(;par[r]>0;r=par[r])
		;
	while(par[v]>0){
		int t=par[v];
		par[v]=r;
		v=t;
	}
	return r;
}
void union2(int r1,int r2){
	/*if(par[r1]<par[r2]){
		par[r1]+=par[r2];
		par[r2]=r1;
	}else{
		par[r2]+=par[r1];*/
		par[r1]=r2;
//	}
}
bool cmp(fami f1,fami f2){
	if(abs(f1.area-f2.area)>1e-8)
		return f1.area>f2.area;

	return f1.id<f2.id;
}
int main(){
	int n;
	scanf("%d",&n);
	fill(par,par+10005,-INF);

	for(int i=0;i<n;i++){
		pe p;vector<int> fam;
		scanf("%d%d%d%d",&p.id,&p.fa,&p.ma,&p.k);
		par[p.id]=-1;
		if(p.fa>=0){par[p.fa]=-1;p.family.push_back(p.fa);}
		if(p.ma>=0){par[p.ma]=-1;p.family.push_back(p.ma);}
		for(int j=0;j<p.k;j++){
			int ch;
			scanf("%d",&ch);
			par[ch]=-1;
			p.family.push_back(ch);
		}
		scanf("%lf%lf",&p.sets,&p.area);
		l[p.id]=p;
	}

	for(auto it=l.begin();it!=l.end();it++){
		for(int j=0;j<it->second.family.size();j++){
			int r1=root(it->first);
			int r2=root(it->second.family[j]);
			if(r1!=r2)
				union2(r1,r2);
		}
	}
	map<int,fami> ans;
	for(int i=0;i<10005;i++){
		if(par[i]!=-INF){

			int r=root(i);
			if(ans.find(r)==ans.end()){
				fami f;
				f.area=0;f.id=i;f.num=0;f.sets=0;
				ans[r]=f;
			}
			ans[r].num++;

			if(l.find(i)!=l.end()){
				ans[r].area+=l[i].area;
				ans[r].sets+=l[i].sets;
			}
		}
	}
	vector<fami> ansorder;
	for(auto it=ans.begin();it!=ans.end();it++){
		it->second.area=it->second.area/it->second.num;
		it->second.sets=it->second.sets/it->second.num;
		ansorder.push_back(it->second);
	}
	sort(ansorder.begin(),ansorder.end(),cmp);
	printf("%d\n",ans.size());
	for(int i=0;i<ansorder.size();i++){
		printf("%04d %d %.3f %.3f\n",ansorder[i].id,ansorder[i].num,ansorder[i].sets,ansorder[i].area);
	}
	getchar();
	getchar();
	return 0;
}