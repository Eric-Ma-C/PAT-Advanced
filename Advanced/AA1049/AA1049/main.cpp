#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
vector<string> l;
string nobegin0(string s){
	int k=0;
	for(;k<s.size()&&s[k]=='0';k++)//È¥Ê×Î»Áã
		;
	return s.substr(k);
}
string getcmpt(int insert,int len){
	string cmpt;
	while(cmpt.size()<len&&insert<l.size())
		cmpt+=l[insert++];
	return cmpt;
}
string getbegincmpt(int insert,int len){
	string cmpt;
	while(cmpt.size()<len&&insert<l.size())
		cmpt+=nobegin0(l[insert++]);
	return cmpt;
}
bool isall0(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]!='0')
			return false;
	}
	return true;
}
int main(){
	int n;
	scanf("%d",&n);

	char tmp[10];
	for(int i=0;i<n;i++){
		scanf("%s",tmp);
		string ts(tmp);

		if(isall0(ts))
			continue;

		int insert=0;
		for(;insert<l.size();insert++){

			string cmpt,ts2;
			if(insert==0){ 
				ts2=nobegin0(ts);
				cmpt=getbegincmpt(insert,ts2.size());
			}else{ 
				ts2=ts;
				cmpt=getcmpt(insert,ts2.size());
			}
			int len=ts2.size();
			if(cmpt.size()>=len){
				cmpt=cmpt.substr(0,len);
			}else{
				ts2=ts2.substr(0,cmpt.size()); 
			}
			if(cmpt>ts2){
				break;
			}
		}
		if(insert==l.size()&&l.size()>0){//last compare specially
			string s1=l[l.size()-1]+ts;
			string s2=ts+l[l.size()-1];
			if(s1>s2) insert=l.size()-1;
			else insert=l.size();
		}
		l.insert(l.begin()+insert,ts);
	}
	if(l.size()>0)
		l[0]=nobegin0(l[0]);
	if(l.size()==0)
		l.push_back("0");
	for(int i=0;i<l.size();i++){
		printf("%s",l[i].c_str());
	}
	getchar();
	getchar();
	return 0;
}

//3 012 0123 0000