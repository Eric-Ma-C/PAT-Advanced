#include<stdio.h>
#include<string.h>
#include<stack>
//14min
char n[105]={0};

void prt(int i){
	switch(i){
	case 0:
		printf("zero");
		break;
		case 1:
		printf("one");
		break;
		case 2:
		printf("two");
		break;
		case 3:
		printf("three");
		break;
		case 4:
		printf("four");
		break;
		case 5:
		printf("five");
		break;
		case 6:
		printf("six");
		break;
		case 7:
		printf("seven");
		break;
		case 8:
		printf("eight");
		break;
		case 9:
		printf("nine");
		break;
	}
}
int main(){

	scanf("%s",n);
	int len=strlen(n);
	int sum=0;
	for(int i=0;i<len;i++){
		sum+=n[i]-'0';
	}
	std::stack<int> s;
	while(sum){
		s.push(sum%10);
		sum/=10;
	}
	bool fir=1;
	while(!s.empty()){
		if(fir){fir=0;}
		else printf(" ");

		prt(s.top());
		s.pop();
	}

	getchar();
	getchar();
	return 0;
}