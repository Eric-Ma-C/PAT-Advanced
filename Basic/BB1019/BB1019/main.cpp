#include<stdio.h>
char bro[80]={0};
	int p=0;

	void addBro(char c){
		if(c>='a'&&c<='z'){
			c+=('A'-'a');
		}
		int i=0;
		for(;i<p;i++){
			if(bro[i]==c)
				break;
		}
		if(i==p){
		bro[i]=c;
		p++;
		}
	}
int main(){
	char str[81],real[81];
	scanf("%s\n%s",str,real);

	
	int i=0,j=0;
	while(str[i]!='\0'&&real[j]!='\0'){
		if(real[j]=='_'&&str[i]!='_'){
			while(str[i]!='_'){
				addBro(str[i]);
				i++;
			}

		}else if(str[i]==real[j]){
			i++;j++;
		}else{
			addBro(str[i]);
			i++;
		}
	}

	if(real[j]=='\0'){
		while(str[i]!='\0'){
		addBro(str[i]);
		i++;
		}
	}
	
	for(int i=0;i<p;i++){
		printf("%c",bro[i]);
	}


getchar();
getchar();
return 0;
}