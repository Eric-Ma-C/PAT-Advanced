#include<stdio.h>
#include<sstream>
#include<string>
using namespace std;
//55min
int string2int(string s){
	if(s.length()==0)
		return 0;
	int i;
	stringstream stream(s);
	stream >> i;
	return i;
}

int main(){
	char n[15];
	scanf("%s",n);
	int count=0;
	string st(n);
	for(int i=0;i<st.size();i++){
		int k=i+1;
		int bit=st[st.size()-k]-'0';
		int pre=string2int(st.substr(0,st.size()-k));
		int post=string2int(st.substr(st.size()-k+1));

		if(bit==0){
			int j=k-1;int tmp=pre;
			while(j--)
				tmp*=10;
			count+=tmp;
		}else if(bit==1){
			count+=post+1;
			int j=k-1;int tmp=pre;
			while(j--)
				tmp*=10;
			count+=tmp;
		}else if(bit>1){
			int j=k-1;int tmp=pre+1;
			while(j--)
				tmp*=10;
			count+=tmp;
		}
	}
	printf("%d",count);
	getchar();
	getchar();
	return 0;
}