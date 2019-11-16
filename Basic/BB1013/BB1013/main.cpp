#include<stdio.h>
using namespace std;

int main(){
	int a[10];
	for(int i=0;i<10;i++)
	scanf("%d",a+i);

	int first=1;
	while(first<10&&a[first]==0)
		first++;

	if(first==10){
		printf("0");
		return 0;
	}

	printf("%d",first);
	a[first]--;

	for(int j=0;j<10;j++){
		while(a[j]-->0)
			printf("%d",j);
	}
	
	getchar();
	getchar();
	return 0;
}