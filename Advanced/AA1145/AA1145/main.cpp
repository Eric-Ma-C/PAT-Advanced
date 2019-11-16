#include<stdio.h>
#include<unordered_set>
#include<algorithm>
using namespace std;
int msize,n,m;
int size;
int q[10005];
int htable[15000];
bool isprime(int i){
	if(i==2||i==3)return true;
	if(i<2)return false;
	for(int j=2;j*j<=i;j++){
	if(i%j==0)
		return false;
	}
	return true;
}
int getsize(){
	int i=msize;
	for(;!isprime(i);i++)
		;
	return i;
}
bool insertt(int t){
	for(int i=0;i<size;i++){
		if(htable[(t+i*i)%size]<0){
			htable[(t+i*i)%size]=t;
			return true;
		}
	}
	return false;
}
int findt(int t){
	for(int i=0;i<size;i++){
		if(htable[(t+i*i)%size]==t||htable[(t+i*i)%size]<0){
			return i+1;
		}
	}
	return size+1;
}
int main(){
	scanf("%d %d %d",&msize,&n,&m);
	fill(htable,htable+15000,-1);
	size=getsize();
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		if(!insertt(t)){
			printf("%d cannot be inserted.\n",t);
		}
	}
	int count=0;
	for(int i=0;i<m;i++){
		int t;
		scanf("%d",&t);
		count+=findt(t);
	}
	printf("%.1f",count*1.0/m);
	getchar();
	getchar();
	return 0;
}

