#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
//20min
typedef struct node{
	int addr,data,next;
}node; 
node l[100005];
int main(){
	int head,n,K;
	scanf("%d%d%d",&head,&n,&K);
	for(int i=0;i<n;i++){
		int a,v,n;
		scanf("%d %d %d",&a,&v,&n);
		l[a].addr=a;l[a].data=v;l[a].next=n;
	}
	vector<node> ans;
	int size=0;
	for(int i=head;i!=-1;i=l[i].next){
		ans.push_back(l[i]);
		size++;
	}
	int count=size/K;
	int tmp=head;
	for(int i=0;i<count;i++){
		reverse(ans.begin()+i*K,ans.begin()+i*K+K);
	}
	int i=0;
	for(;i<ans.size()-1;i++){
		printf("%05d %d %05d\n",ans[i].addr,ans[i].data,ans[i+1].addr);
	}
	printf("%05d %d -1\n",ans[i].addr,ans[i].data);

	getchar();
	getchar();
	return 0;
}

