#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int d,n;
	scanf("%d %d",&d,&n);
	char c=d+'0';
	string s;s+=c;
	for(int i=1;i<n;i++){
		string tmp;
		int num=0;char t=' ';
		for(int i=0;i<s.size();i++){
			if(t!=s[i]){
				if(t!=' '){
					tmp+=t;
					tmp+='0'+num;
				}
				t=s[i];
				num=1;
			}else{
				num++;
			}
		}
		tmp+=t;
		tmp+='0'+num;
		s=tmp;
	}
	printf("%s",s.c_str());

	getchar();
	getchar();
	return 0;

}