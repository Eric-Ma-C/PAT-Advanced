#include<stdio.h>
#include<map>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

typedef struct item{
	int id,weight,headid;
	string name;
}item;
typedef struct gang{
	int headid,totalweight,num;
}gang;
int p[2005];
int g[2005][2005];
int n,k;
map<string,int> toid;
item plist[2005];

int root(int i){
	int r=i;
	while(p[r]>=0){
		r=p[r];
	}
	while(p[i]>=0){//路径压缩
		int t=i;
		i=p[i];
		p[t]=r;
	}
	return r;
}
void unionij(int r1,int r2){
	if(plist[r1].weight>plist[r2].weight){
		p[r1]+=p[r2];//权重的做head
		p[r2]=r1;
	}else{
		p[r2]+=p[r1];
		p[r1]=r2;
	}
}
int main(){
	scanf("%d %d",&n,&k);
	int id=0;
	fill(g[0],g[2004]+2005,0);
	for(int i=0;i<n;i++){
		char n1[5],n2[5];int time;
		scanf("%s %s %d",n1,n2,&time);
		string s1(n1);
		string s2(n2);
		if(toid.find(s1)==toid.end()){
			toid[s1]=id;
			plist[id].name=s1;
			plist[id].id=id++;
		}
		if(toid.find(s2)==toid.end()){
			toid[s2]=id;
			plist[id].name=s2;
			plist[id].id=id++;
		}
		int id1,id2;
		id1=toid[s1];
		id2=toid[s2];
		g[id1][id2]+=time;
		g[id2][id1]+=time;
	}
	fill(p,p+2005,-1);
	for(int i=0;i<id;i++){//计算权值
		plist[i].weight=0;
		for(int j=0;j<id;j++){
			plist[i].weight+=g[i][j];
		}
	}
	for(int i=0;i<id;i++){
		for(int j=0;j<i;j++){
			if(g[i][j]>0){
				int r1=root(i);
				int r2=root(j);
				if(r1!=r2)
					unionij(r1,r2);
			}
		}
	}
	map<string,gang> glist;
	for(int i=0;i<id;i++){
		int r=root(i);
		if(p[r]<-2){ 
			plist[i].headid=r;
			string name=plist[r].name;
			if(glist.find(name)==glist.end()){
				gang g;g.headid=r;g.num=0;g.totalweight=0;
				glist[name]=g;
			}
			glist[name].num++;glist[name].totalweight+=plist[i].weight;
		}
		else plist[i].headid=-1;//成员太少
	}
	for(auto it=glist.begin();it!=glist.end();it++){
		it->second.totalweight/=2;
	}
	for(auto it=glist.begin();it!=glist.end();){
		if(it->second.totalweight<=k){
			glist.erase(it);
			it=glist.begin();
		}else it++;
	}
	printf("%d\n",glist.size());
	for(auto it=glist.begin();it!=glist.end();it++){
		printf("%s %d\n",it->first.c_str(),it->second.num);
	}

	getchar();
	getchar();
	return 0;
}