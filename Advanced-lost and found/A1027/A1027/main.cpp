#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
//36min  ÖÊÊıÅĞ¶Ï×¢Òân=1,0,-1,-2....
char tmp[20]={0};
void toR(int n,int d){
	fill(tmp,tmp+20,'\0');
	int i=0;
	while(n){
		tmp[i++]=n%d+'0';
		n/=d;
	}
}
bool isprime(int n){
	if(n<2)
		return false;
	for(int i=2;i<=sqrt(n*1.0);i++){
		if(n%i==0)
			return false;
	}
	return true;
}
int getReverseDec(int d){
	int ans=0;
	for(int i=0;i<strlen(tmp);i++){
		ans*=d;
		ans+=(tmp[i]-'0');
	}
	return ans;
}
int main(){
	int n,d;

	while(1){
		scanf("%d",&n);
		if(n<0)
			break;
		scanf("%d",&d);
		toR(n,d);
		int reverse=getReverseDec(d);
		if(isprime(n)&&isprime(reverse)){printf("Yes\n");}
		else printf("No\n");

	};
	getchar();
	getchar();
	return 0;
}