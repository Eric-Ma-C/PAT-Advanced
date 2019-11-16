#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef struct node{
	int addr,v,next;
}node;
int main(){
	int h,n,k;
	scanf("%d%d%d",&h,&n,&k);
	map<int,node> ori;
	for(int i=0;i<n;i++){
		node nd;
		scanf("%d%d%d",&nd.addr,&nd.v,&nd.next);
		ori[nd.addr]=nd;
	}
	vector<node> v1,v2,v3;
	for(int i=h;i!=-1;i=ori[i].next){
		if(ori[i].v<0)
			v1.push_back(ori[i]);
		else if(ori[i].v<=k)
			v2.push_back(ori[i]);
		else
			v3.push_back(ori[i]);
	}
	vector<node> ans;
	for(int i=0;i<v1.size();i++){
		ans.push_back(v1[i]);
	}
	for(int i=0;i<v2.size();i++){
		ans.push_back(v2[i]);
	}
	for(int i=0;i<v3.size();i++){
		ans.push_back(v3[i]);
	}

	for(int i=0;i<ans.size()-1;i++){
		printf("%05d %d %05d\n",ans[i].addr,ans[i].v,ans[i+1].addr);
	}
	printf("%05d %d -1",ans[ans.size()-1].addr,ans[ans.size()-1].v);

	getchar();
	getchar();
	return 0;
}