#include<stdio.h>
//10min
int main(){
	int g1,s1,k1,g2,s2,k2;
	scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
	int g,s,k,c=0;
	k=k1+k2;if(k>28){c=1;k=k%29;}
	s=s1+s2+c;c=0;if(s>16){c=1;s=s%17;}
	g=g1+g2+c;
	printf("%d.%d.%d",g,s,k);
	getchar();
	getchar();
return 0;
}