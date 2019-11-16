#include<stdio.h>
using namespace std;
#include<string.h>
#include<math.h>

#define SEG_NUM 8

int getIntLen(int a){
	int len=0;
	while(a/=10)
		len++;

	return len+1;
}
int main(){
	char a[1001],q[1001];
	int b,r;

	scanf("%s %d",a,&b);
	
	int pa=0,pb=0;
	
	int len=0,tmpQ=0,tmpR=0;
	int tmp=0;
	bool isF=true;
	for(int i=0;a[i]!='\0';i++){
		if(len>=SEG_NUM){
		//cal
			tmp=tmpR*pow(10.0,len)+tmp;
			tmpQ=tmp/b;
			tmpR=tmp%b;
			if(isF){
			 isF=false;
			}else{
				int lenQ=getIntLen(tmpQ);		
				len-=lenQ;
				while(len--)
					printf("0");
			}
			printf("%d",tmpQ);

			len=0;
			tmp=0;
		}

			tmp=tmp*10+a[i]-'0';
			len++;
		
		
	}

	if(len!=0){
		//cal
		tmp=tmpR*pow(10.0,len)+tmp;
		tmpQ=tmp/b;
		tmpR=tmp%b;
		if(isF){
			 isF=false;
		}else{
			int lenQ=getIntLen(tmpQ);		
				len-=lenQ;
				while(len--)
					printf("0");
		}
		printf("%d",tmpQ);
	}
	
	printf(" %d",tmpR);
	getchar();
	getchar();
	return 0;
}