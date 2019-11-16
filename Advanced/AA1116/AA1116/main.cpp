#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
bool visited[10000]={0};

int r[10000];
bool isprime(int n){
	if(n==2)
		return true;

	for(int i=2;i*i<=n;i++){
		if(n%i==0)
			return false;
	}
	return true;
}
int main(){
	int n;
	scanf("%d",&n);
	fill(r,r+10000,-1);
	for(int i=0;i<n;i++){
		int id;
		scanf("%d",&id);
		r[id]=i+1;
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int id;
		scanf("%d",&id);

		printf("%04d: ",id);
		if(r[id]==-1){
			printf("Are you kidding?\n");
		}else if(visited[id]==true){
			printf("Checked\n");
		}else if(r[id]==1){
			printf("Mystery Award\n");
		}else if(isprime(r[id])){
			printf("Minion\n");
		}else{
			printf("Chocolate\n");		
		}
			visited[id]=true;

	}


	getchar();
	getchar();
	return 0;
}