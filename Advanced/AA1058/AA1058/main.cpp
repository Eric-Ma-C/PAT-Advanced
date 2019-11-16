#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
char toUper(char a){
	if(a>='a'&&a<='z')
		return a+'A'-'a';
	return a;
}
bool issame(char a,char b){
	if(a==b)
		return true;
	if(a>='a'&&a<='z'&&b==a+'A'-'a')
		return true;
	if(b>='a'&&b<='z'&&a==b+'A'-'a')
		return true;

	return false;
}
int main(){
	char a[100],b[100];
	scanf("%s%s",a,b);
	vector<int> ans;
	int i=0,j=0;
	for(;i<strlen(a)&&j<strlen(b);){
		if(issame(a[i],b[j])){
			i++;j++;
		}else{
			for(;a[i]!=b[j]&&i<strlen(a);i++){
				ans.push_back(toUper(a[i]));
			}
		}
	}
	for(;i<strlen(a);i++){
		ans.push_back(toUper(a[i]));
	}
	set<int> t;
	for(int i=0;i<ans.size();i++){
		if(t.find(ans[i])==t.end())
			t.insert(ans[i]);
		else{
			ans.erase(ans.begin()+i);
			i--;
		}
	}
	for(int i=0;i<ans.size();i++){
		printf("%c",ans[i]);
	}

	getchar();
	getchar();
	return 0;
}