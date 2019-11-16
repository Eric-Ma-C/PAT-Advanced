#include<stdio.h>
#include<stdlib.h>
//30min
int main(){
	long n1,n2;
	scanf("%ld",&n1);
	long* l1=(long*)malloc(sizeof(long)*n1);
	for(long i=0;i<n1;i++){
		scanf("%ld",l1+i);
	}
	scanf("%ld",&n2);
	long* l2=(long*)malloc(sizeof(long)*n2);
	for(long i=0;i<n2;i++){
		scanf("%ld",l2+i);
	}
	long med=(n1+n2+1)/2;

	long p1=0,p2=0;
	long ans=0;
	while(med>0){
		if(l1[p1]>l2[p2]){
			ans=l2[p2++];}
		else{
			ans=l1[p1++];}

		med--;
	}

	printf("%ld",ans);

	getchar();
	getchar();
	return 0;
}