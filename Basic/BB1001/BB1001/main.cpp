#include<stdio.h>
using namespace std;
//4
//1 2 3
//2 3 4
//2147483647 0 2147483646
//0 -2147483648 -2147483647
int main(){
	int m=0;

	scanf("%d",&m);

	if(m>10)
		return 0;
	
	long long a,b,c;
	
	for(int i=0;i<m;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		long long sum=a+b;
		if(sum-c>0){
			printf("Case #%d: true\n",i+1);
		}else{
			printf("Case #%d: false\n",i+1);
		}
		
		
	}

	return 0;
}