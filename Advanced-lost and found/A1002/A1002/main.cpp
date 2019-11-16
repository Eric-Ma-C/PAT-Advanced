#include<stdio.h>
#include<string>
using namespace std;
int last=-1;
void spell(int n){
	switch(n){
	case 0:
		if(last==0){
			last=0;
			return;
		}
		printf("ling");
		break;
	case 1:
		printf("yi");
		break;
	case 2:
		printf("er");
		break;
	case 3:
		printf("san");
		break;
	case 4:
		printf("si");
		break;
	case 5:
		printf("wu");
		break;
	case 6:
		printf("liu");
		break;
	case 7:
		printf("qi");
		break;
	case 8:
		printf("ba");
		break;
	case 9:
		printf("jiu");
		break;
	}

	last=n;
}
void spell4(string s,bool isFirst,bool isWan){
	if(isWan&&s.compare("0000")==0){
		printf(" ling");return;}
	int j=s.length()-1;
	for(;j>=0&&s[j]=='0';j--)
		;
	int zero=s.length()-1-j;

	for(int i=0;i<s.length()-zero;i++){
		if(!isFirst||i!=0)
			printf(" ");

		if(s[i]=='0'){
			while(s[i]=='0'&&i<s.length()-zero){
				i++;
			}
			i--;
		}

		spell(s[i]-'0');

		if(s[i]-'0'!=0){
			switch(s.length()-i){
			case 1:
				//printf("Yi");
				break;
			case 2:
				printf(" Shi");
				break;
			case 3:
				printf(" Bai");
				break;
			case 4:
				printf(" Qian");
				break;

			}
		}
	}

	if(isWan&&s.compare("0000")){
		printf(" Wan");
	}
}
int main(){
	char n[11];
	scanf("%s",n);

	string str=n;
	if(str[0]=='-'){
		printf("Fu ");
		str=str.substr(1);
	}

	if(str.compare("0")==0){
	printf("ling");
	return 0;
	}

	int len=str.size();

	if(len==9){
		spell(str[0]-'0');
		printf(" Yi");
		spell4(str.substr(1,4),false,true);
		spell4(str.substr(5,4),false,false);
	}else if(len>4){
		spell4(str.substr(0,len-4),true,true);
		spell4(str.substr(len-4,4),false,false);
	}else{
		spell4(str,true,false);
	}
	getchar();
	getchar();
	return 0;
}