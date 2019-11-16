#include<stdio.h>
using namespace std;

int toD(int n,int d,char* ans){
	int i=0;
	while(n/d){
		ans[i++]=n%d+'0';
		n/=d;
	}

	ans[i]=n+'0';
	return i;
}
int main(){
	int a,b,d;
	scanf("%d %d %d",&a,&b,&d);

	char ans[20];
	int num=toD(a+b,d,ans);

	int j=0;
	while(num>=0)
		printf("%c",ans[num--]);
	getchar();
	getchar();
return 0;
}