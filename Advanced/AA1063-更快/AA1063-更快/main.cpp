#include<stdio.h>
#include<string.h>
int main(){
	char c[100005];
	scanf("%s",c);
	long long p=0,pa=0,pat=0;
	int len=strlen(c);
	for(int i=0;i<len;i++){
		if(c[i]=='P'){
			p++;
		}else if(c[i]=='A'){
			pa+=p;
			pa=pa%1000000007;
		}else{
			pat+=pa;
			pat=pat%1000000007;
		}
	}
	printf("%lld",pat);
	getchar();
	getchar();
	return 0;
}