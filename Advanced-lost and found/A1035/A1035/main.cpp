#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
//80min
string sum(string s1,string s2){
	string s;
	int carry=0;//½øÎ»
	int i=0;
	for(;i<s1.size()&&i<s2.size();i++){
		int t=s1[i]-'0'+s2[i]-'0'+carry;
		carry=t>9?1:0;
		t=t-(carry?10:0);
		char c[2]={0};
		c[0]=t+'0';
		s.insert(0,c);
	}
	if(s1.size()==s2.size()){
		if(carry){
			char c[2]={0};
			c[0]='1';
			s.insert(0,c);
		}
		return s;
	}
	for(;i<s1.size();i++){
		int t=s1[i]-'0'+carry;
		carry=t>9?1:0;
		t=t-(carry?10:0);
		char c[2]={0};
		c[0]=t+'0';
		s.insert(0,c);
	}
	for(;i<s2.size();i++){
		int t=s2[i]-'0'+carry;
		carry=t>9?1:0;
		t=t-(carry?10:0);
		char c[2]={0};
		c[0]=t+'0';
		s.insert(0,c);
	}
	return s;
}
int main(){
	char n[50];int k;
	scanf("%s %d",n,&k);

	int i=0;string s=n,sr=n;
	for(;i<k;i++){
		sr=s;
		reverse(sr.begin(),sr.end());
		if(sr==s){
			break;
		}
		s=sum(s,sr);
	}
	printf("%s\n%d",s.c_str(),i);

	getchar();
	getchar();
	return 0;
}