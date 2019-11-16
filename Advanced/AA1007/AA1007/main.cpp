#include<stdio.h>
#include<math.h>
//28min
int main(){
	int n;
	scanf("%d",&n);

	int begin=2,len=0;
	int max=sqrt(n*1.0)+1;
	for(int i=begin;i<max;i++){
		int tmp=n,tlen=0;
		int j=i;
		while(tmp%j==0){
			tmp/=j;
			j++;
			tlen++;
		}
		if(tlen>len){
			begin=i;
			len=tlen;
		}
	}
	if(len==0){len=1;begin=n;}
	printf("%d\n%d",len,begin);
	while(len-->1)
	printf("*%d",++begin);

getchar();
getchar();
return 0;
}