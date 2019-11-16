#include<stdio.h>
//using namespace std;
//#include<string.h>
int main(){
	char a[10000];
	bool isPos=true,isEPos=true;
	int exp=0;
	scanf("%s",a);

	if(a[0]=='-')
		isPos=false;

	int i=0,posE=0;
	for(;a[i]!='E';i++)
		;

	posE=i;
	if(a[++i]=='-')
		isEPos=false;
	//int len=strlen(a)-1;
	i++;
	while(a[i]!='\0'){
		exp=exp*10+a[i]-'0';
		i++;
	}
	if(!isPos)
		printf("-");

	if(isEPos){
		printf("%c",a[1]);
		int j=0;
		for(;j<exp;j++){
			if(3+j>=posE)
				printf("0");
			else
				printf("%c",a[3+j]);
		}
		if(3+j<posE)
				printf(".");
		while(3+j<posE)
			printf("%c",a[3+j]);
	}else{
	
		printf("0.");
		for(int k=0;k<exp-1;k++)
			printf("0");

		printf("%c",a[1]);
		for(int j=0;j+3<posE;j++)
			printf("%c",a[3+j]);
	}
	
	getchar();
	getchar();
	return 0;
}