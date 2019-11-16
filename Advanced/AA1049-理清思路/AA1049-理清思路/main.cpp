#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string> l;
bool isZero(string s){//是否全零
	for(int i=0;i<s.size();i++){
		if(s[i]!='0')
			return false;
	}
	return true;
}
bool cmp(string &s1,string &s2){
	//if((s1.length()<s2.length()&&s2.find(s1)==0)||
	//	(s2.length()<s1.length()&&s1.find(s2)==0))//是前缀
	//	return s1+s2<s2+s1;//小的在前面
	//else
		return s1+s2<s2+s1;
}
int main(){
	int n;
	scanf("%d",&n);

	char tmp[15];
	for(int i=0;i<n;i++){
		scanf("%s",tmp);
		if(isZero(tmp))//全零放开头，不考虑
			continue;
		l.push_back(string(tmp));
	}
	sort(l.begin(),l.end(),cmp);//字符串排序

	if(l.size()>0){
		int k=0;
		for(;k<l[0].size()&&l[0][k]=='0';k++)//去首位零
			;
		l[0]=l[0].substr(k);
	}
	if(l.size()==0)//特判全0
		l.push_back("0");

	for(int i=0;i<l.size();i++){
		printf("%s",l[i].c_str());
	}
	getchar();
	getchar();
	return 0;
}

//4 12 121 0123 0000
//5 32 321 3214 0229 87