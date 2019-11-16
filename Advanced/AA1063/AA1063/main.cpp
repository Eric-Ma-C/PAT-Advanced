#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
//³¬Ê±
char c[100005]={0};
int pnum[100005]={0};
vector<int> t;
vector<int> a;
int main(){
	scanf("%s",c);
	int len=strlen(c);
	pnum[0]=c[0]=='P'?1:0;

	for(int i=1;i<len;i++){
		if(c[i]=='P'){
			pnum[i]=pnum[i-1]+1;
		}else{
			pnum[i]=pnum[i-1];
		}
		if(c[i]=='A'){
			a.push_back(i);
		}
		if(c[i]=='T'){
			t.push_back(i);
		}
	}
	long long count=0;
	for(int i=0;i<t.size();i++){
		int tmpt=t[i];
		for(int j=0;j<a.size()&&a[j]<tmpt;j++){
			count+=pnum[a[j]];
			count=count%1000000007;
		}
	}

	printf("%lld",count);
	getchar();
	getchar();
	return 0;
}