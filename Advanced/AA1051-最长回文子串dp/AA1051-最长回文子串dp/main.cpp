#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
bool dp[1005][1005]={0};
int main(){
	char c[1100];
	cin.getline(c,1006);
	int len=strlen(c);
	dp[0][0]=true;
	for(int i=1;i<len;i++){
		dp[i][i]=true;
		if(c[i]==c[i-1]){
			dp[i-1][i]=true;
		}
	}
	for(int tlen=3;tlen<=len;tlen++){
		for(int j=0;j+tlen-1<len;j++){
			if(c[j]==c[j+tlen-1]&&dp[j+1][j+tlen-2]==true)
				dp[j][j+tlen-1]=true;
			else
				dp[j][j+tlen-1]=false;
		}
	}

	int mi=0,mj=0;
	for(int i=0;i<len;i++){
		for(int j=i;j<len;j++){
			if(dp[i][j]==true&&j-i>mj-mi){
				mj=j;mi=i;
			}
		}
	}
	printf("%d",mj-mi+1);

	getchar();
	getchar();
	return 0;
}