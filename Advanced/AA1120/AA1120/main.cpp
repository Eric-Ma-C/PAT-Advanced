#include<stdio.h>
#include<string.h>
#include<set>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	set<int> ans;
	for(int i=0;i<n;i++){
		char str[50];
		scanf("%s",str);

		int sum=0;
		for(int j=0;j<strlen(str);j++){
			sum+=str[j]-'0';
		}
		ans.insert(sum);
	}
	printf("%d\n",ans.size());
	for(auto it=ans.begin();it!=ans.end();it++){
		if(it!=ans.begin())printf(" ");
		printf("%d",*it);
	}
	getchar();
	getchar();
	return 0;
}