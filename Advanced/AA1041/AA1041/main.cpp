#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
//22min
typedef struct node{
	int addr,next,v;
}node;
node l[100005];
bool cmp(node &n1,node &n2){
	return n1.v<n2.v;
}
int main(){
	int n,head;
	scanf("%d %d",&n,&head);

	for(int i=0;i<n;i++){
		int addr;
		scanf("%d",&addr);
		scanf("%d %d",&l[addr].v,&l[addr].next);
		l[addr].addr=addr;
	}
	vector<node> li;
	for(int i=head;i!=-1;i=l[i].next)
		li.push_back(l[i]);

	if(li.size()==0){
		printf("%d %d\n",li.size(),-1);
		return 0;
	}
	sort(li.begin(),li.end(),cmp);
	printf("%d %05d\n",li.size(),li[0].addr);
	int i=0;
	for(;i<li.size()-1;i++){
		printf("%05d %d %05d\n",li[i].addr,li[i].v,li[i+1].addr);
	}
	printf("%05d %d %d\n",li[i].addr,li[i].v,-1);

	getchar();
	getchar();
	return 0;
}