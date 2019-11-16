#include<stdio.h>
//27min
int main(){
	int n,b;
	scanf("%d %d",&n,&b);

	int a[35];int size=0;
	for(int i=0;n;i++,size++){
		a[i]=n%b;
		n/=b;
	}
	bool tag=true;
	for(int i=0;i<size/2;i++){
		if(a[i]!=a[size-i-1]){
			tag=false;break;
		}
	}
	if(tag)printf("Yes\n");
	else printf("No\n");
	for(int i=size-1;i>0;i--)
		printf("%d ",a[i]);

	printf("%d",a[0]);

	getchar();
	getchar();
	return 0;
}