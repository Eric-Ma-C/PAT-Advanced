#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int t[100005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",t+i);
	}
	sort(t,t+n);
	int ans=1;
	for(int i=n-1;i>=0;i--,ans++){
		if(t[i]<=ans)
			break;
	}
	printf("%d",ans-1);

	getchar();
	getchar();
	return 0;
}