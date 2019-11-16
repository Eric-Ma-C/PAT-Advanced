#include<stdio.h>
#include<unordered_map>
#include<utility>
#include<vector>
#include<set>
using namespace std;
//40min
unordered_map<int,pair<int,int> > mem;
int main(){
	int head,n;
	scanf("%d %d",&head,&n);
	int addr;//,v,next;
	for(int i=0;i<n;i++){
		pair<int,int> p;
		scanf("%d %d %d",&addr,&p.first,&p.second);
		mem[addr]=p;
	}
	set<int> s;vector<pair<int,pair<int,int> > > v1,v2;
	for(addr=head;addr!=-1;addr=mem[addr].second){
		if(s.find(mem[addr].first)==s.end()){//show in first time
			s.insert(mem[addr].first);
			s.insert(-mem[addr].first);
			v1.push_back(pair<int,pair<int,int> >(addr,mem[addr]));
		}else{
			v2.push_back(pair<int,pair<int,int> >(addr,mem[addr]));
		}
	}
	auto it=v1.begin();
	if(v1.size()>0){
		for(;it!=v1.end()-1;it++){
			printf("%05d %d %05d\n",it->first,it->second.first,(it+1)->first);
		}
		printf("%05d %d %d\n",it->first,it->second.first,-1);
	}
	it=v2.begin();
	if(v2.size()>0){
		for(;it!=v2.end()-1;it++){
			printf("%05d %d %05d\n",it->first,it->second.first,(it+1)->first);
		}
		printf("%05d %d %d\n",it->first,it->second.first,-1);
	}
	getchar();
	getchar();
	return 0;
}