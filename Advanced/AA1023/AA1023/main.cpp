#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		bool big=(a+b)>c?true:false;
		if(a>0&&b>0)
			if(a+b<=0)
				big=true;
		if(a<0&&b<0)
			if(a+b>=0)
				big=false;

		printf("Case #%d: ",i+1);
		if(big) printf("true\n");
		else printf("false\n");
	}
	getchar();
	getchar();
	return 0;
}