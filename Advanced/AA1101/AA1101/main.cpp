#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
//30min ×¢Òâ¸ñÊ½
int a[100005];
int permax[100005];
int postmin[100005];
int main(){
	int n;
	scanf("%d",&n);
	int min=0x7fffffff,max=0;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		if(a[i]>max){
			max=a[i];
		}
		permax[i]=max;
	}
	for(int i=n-1;i>=0;i--){
		if(a[i]<min){
			min=a[i];
		}
		postmin[i]=min;
	}
	vector<int> ans;
	for(int i=0;i<n;i++){
		if(a[i]<=postmin[i]&&a[i]>=permax[i]){
			ans.push_back(a[i]);
		}
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		if(i!=0)printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	getchar();
	getchar();
	return 0;
}