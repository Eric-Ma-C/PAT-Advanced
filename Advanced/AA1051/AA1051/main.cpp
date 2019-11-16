#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int dp[1005][1005]={0};
int main(){
	char c[1100];
	cin.getline(c,1006);
	int len=strlen(c);
	dp[0][0]=1;vector<int> len2;
	for(int i=1;i<len;i++){
		dp[i][i]=1;
		if(c[i]==c[i-1]){
			dp[i-1][i]=2;
			len2.push_back(i-1);
		}
	}
	for(int i=1;i<len;i++){
		int k=i-1;
		for(int j=i+1;j<len&&k>=0;j++,k--){
			if(c[k]==c[j])
				dp[k][j]=dp[k+1][j-1]+2;
			else
				dp[k][j]=dp[k+1][j-1];
		}
	}
	for(int i=0;i<len2.size();i++){
		int k=len2[i]-1;
		for(int j=len2[i]+1;j<len&&k>=0;j++,k--){
			if(c[k]==c[j])
				dp[k][j]=dp[k+1][j-1]+2;
			else
				dp[k][j]=dp[k+1][j-1];
		}
	}
	int max=0;
	for(int i=0;i<len;i++){
		for(int j=i;j<len;j++){
		if(dp[i][j]>max)
			max=dp[i][j];
		}
	}
	printf("%d",max);

	getchar();
	getchar();
	return 0;
}