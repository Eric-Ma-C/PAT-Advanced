#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

string add(string s1,string s2){
	string sum;
	int cin=0;
	for(int i=s1.size()-1,j=s2.size()-1;i>=0&&j>=0;i--,j--){
		int a=s1[i]-'0',b=s2[j]-'0';
		int c=a+b+cin;
		if(c>9){ cin=1;c-=10;}
		else cin=0;
		sum.insert(sum.begin(),c+'0');
	}
	if(cin>0)
		sum.insert(sum.begin(),'1');

	return sum;
}
int main(){
	char ch[1005];
	scanf("%s",ch);
	string s(ch);
	string re=s;
	reverse(re.begin(),re.end());
	if(re==s){
		printf("%s is a palindromic number.",s.c_str());
		return 0;
	}

	int count=0;bool ok=false;
	for(;count<10;count++){
		string re=s;
		reverse(re.begin(),re.end());
		string tmp=add(s,re);
		string retmp=tmp;
		reverse(retmp.begin(),retmp.end());

		printf("%s + %s = %s\n",s.c_str(),re.c_str(),tmp.c_str());
		if(retmp==tmp&&tmp[0]!='0'){
			printf("%s is a palindromic number.",tmp.c_str());
			ok=true;
			break;
		}
		s=tmp;
	}
	if(!ok){printf("Not found in 10 iterations.");}
	getchar();
	getchar();
	return 0;

}