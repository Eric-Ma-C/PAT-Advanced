#include<stdio.h>
#include<string.h>
int main(){
	char s[1001],h[1001];
	bool can=true;
	int lack=0;
	scanf("%s",s);
	scanf("%s",h);

	int sizeS=strlen(s);
	int sizeH=strlen(h);
	for(int i=0;i<sizeH;i++){
		bool find=false;
		for(int j=0;j<sizeS;j++){
			if(s[j]==h[i]){
				find=true;
				s[j]='*';
				break;
			}
		}
		if(!find){
			lack++;
		}
	}


	if(lack==0){
		printf("Yes %d",sizeS-sizeH);
	}else{
		printf("No %d",lack);
	}
getchar();
getchar();
return 0;
}