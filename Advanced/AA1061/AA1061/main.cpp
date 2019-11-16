#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
//53min
int t1[105],t2[105],cmp[105];
int n;
bool issame(int *l1,int *l2){
	for(int i=0;i<n;i++){
		if(l1[i]!=l2[i])
			return false;
	}
	return true;
}
bool ismerge(){
	bool pre=false;
	for(int len=2;len<=n;len*=2){
		int i=0;
		for(;i+len<=n;i+=len){
			sort(t2+i,t2+i+len);
		}
		if(i+len>n)
			sort(t2+i,t2+n);

		if(pre&&!issame(cmp,t2)){
			return true;
		}
		if(issame(t2,cmp)){
			pre=true;
		}
	}
	return pre;
}
bool isinsert(){
	bool pre=false;
	for(int i=1;i<n;i++){
		int j=i-1;int tmp=t1[i];
		for(;t1[j]>tmp&&j>=0;j--)
			t1[j+1]=t1[j];
		t1[j+1]=tmp;

		if(pre&&!issame(cmp,t1)){
			return true;
		}
		if(issame(t1,cmp)){
			pre=true;
		}
	}
	return pre;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",t1+i);
		t2[i]=t1[i];
	}
	for(int i=0;i<n;i++){
		scanf("%d",cmp+i);
	}

	if(isinsert()){
		printf("Insertion Sort\n");
		for(int i=0;i<n-1;i++)
			printf("%d ",t1[i]);
		printf("%d",t1[n-1]);
	}
	else if(ismerge()){
		printf("Merge Sort\n");
		for(int i=0;i<n-1;i++)
			printf("%d ",t2[i]);
		printf("%d",t2[n-1]);
	}
	getchar();
	getchar();
	return 0;
}
