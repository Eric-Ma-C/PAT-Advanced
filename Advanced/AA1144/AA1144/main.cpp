#include<stdio.h>
#include<algorithm>
using namespace std;
int num[100005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",num+i);
	}
	sort(num,num+n);
	int ans=1;
	for(int i=0;i<n;i++){
		if(num[i]>ans){
			break;
		}
		if(num[i]==ans){
			ans++;
		}
	}
	printf("%d",ans);
	getchar();
	getchar();
	return 0;
}