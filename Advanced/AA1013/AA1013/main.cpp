#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 11001
//30min
int msize,n;
int hasht[MAX];
bool prime[MAX];
int size;

int insert(int v){
	int h=v%size;
	int i=1,t=h;
	while(hasht[t]!=-1){
		if(i>MAX)
			return -1;
		t=h+i*i;
		t=t%size;
		i++;
	}
	hasht[t]=v;
	return t;
}
int main(){
	scanf("%d %d",&msize,&n);

	fill(hasht,hasht+MAX,-1);
	fill(prime,prime+MAX,true);
	prime[0]=prime[1]=false;
	for(int i=2;i<MAX;i++){
		if(prime[i]){
			for(int j=i+i;j<MAX;j+=i)
				prime[j]=false;
		}
	}
	size=msize;
	for(;!prime[size];size++)
		;
	int t;
	scanf("%d",&t);
	int h=insert(t);
	if(h==-1) printf("-");
	else printf("%d",h);
	for(int i=1;i<n;i++){
		scanf("%d",&t);
		int h=insert(t);
		if(h==-1) printf(" -");
		else printf(" %d",h);
	}
	getchar();
	getchar();
	return 0;
}