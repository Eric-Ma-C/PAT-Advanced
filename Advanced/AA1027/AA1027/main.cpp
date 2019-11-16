#include<stdio.h>
#include<string>
#include<map>
using namespace std;

bool iswordc(char *c){
	if((*c>='0'&&*c<='9')||(*c>='a'&&*c<='z'))
		return true;
	if(*c>='A'&&*c<='Z'){
		*c-='A'-'a';
		return true;
	}
	return false;
}
int main(){
	char c;string wc;
	map<string,int> word;
	bool findend=false;
	while(1){
		scanf("%c",&c);
		
		if(iswordc(&c)){
			if(findend){
				wc+=c;
			}else{
				wc=c;
				findend=true;
			}
		}else{
			if(findend){
				if(word.find(wc)==word.end())
					word[wc]=1;
				else
					word[wc]++;
				findend=false;
			}
		}
		if(c=='\n'){
			break;
		}
	}
	string ans;int max=0;
	for(auto it=word.begin();it!=word.end();it++){
		if(it->second>max){
			max=it->second;ans=it->first;
		}
	}
	printf("%s %d",ans.c_str(),max);

	getchar();
	getchar();
	return 0;
}