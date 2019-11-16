#include<stdio.h>
//13min
int main(){
	int a,b;
	scanf("%d %d",&a,&b);

	int s=a+b;
	if(s<0){
	printf("-");
	s=-s;
	}

	
	if(s/1000000>0){
		printf("%d,",s/1000000);
		s=s%1000000;
		printf("%03d,",s/1000);
		s=s%1000;
		printf("%03d",s);
	}else if(s/1000>0){
		printf("%d,",s/1000);
		s=s%1000;
		printf("%03d",s);
	}else
	printf("%d",s);

	getchar();
	getchar();
	return 0;
}