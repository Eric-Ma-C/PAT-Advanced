#include<stdio.h>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;

int string2int(string s){
	int i;
	stringstream st(s);
	st>>i;
	return i;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char ch[30];
		scanf("%s",ch);

		string str(ch);
		int t=string2int(str);
		int a=string2int(str.substr(0,str.length()/2));
		int b=string2int(str.substr(str.length()/2));
		int c=a*b;
		if(c!=0&&t%c==0)printf("Yes\n");
		else printf("No\n");
	}


	getchar();
	getchar();
	return 0;
}