#include<stdio.h>
using namespace std;


int main(){
	char a[1001];
	scanf("%s",a);

	int num[10]={0};

	for(int i=0;a[i]!='\0';i++){
		num[a[i]-'0']++;
	}

	for(int j=0;j<10;j++){
		if(num[j]!=0)
			printf("%d:%d\n",j,num[j]);
	}

	getchar();
	getchar();
	return 0;
}