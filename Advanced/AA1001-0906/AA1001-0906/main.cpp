#include<stdio.h>
#include<sstream>
#include<string>
using namespace std;

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int s=a+b;
	stringstream sm;
	sm << s;
	string ans=sm.str();
	if(ans[0]=='-'){
		printf("-");
		ans=ans.substr(1);
	}


	if(ans.length()>6){
		printf("%s,",ans.substr(0,ans.length()-6).c_str());
		printf("%s,",ans.substr(ans.length()-6,3).c_str());
		printf("%s",ans.substr(ans.length()-3).c_str());
	}else if(ans.length()>3){
		printf("%s,",ans.substr(0,ans.length()-3).c_str());
		printf("%s",ans.substr(ans.length()-3).c_str());
	}else{
		printf("%s",ans.c_str());	
	}


	getchar();
	getchar();
	return 0;
}