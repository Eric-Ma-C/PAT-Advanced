#include<stdio.h>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int string2int(string s){
	int i;
	stringstream stream(s);
	stream>>i;
	return i;
}
int main(){
	char c[10005];
	scanf("%s",c);

	string s(c);
	int i=s.find("E");
	bool eposi=s[i+1]=='+'?true:false;
	int e=string2int(s.substr(i+2));

	string num=s.substr(0,2)+s.substr(3,i-3);

	if(eposi){
		int doti=e+1;
		while(num.size()<=doti)
			num+='0';
		if(num.size()>doti+1)
			num.insert(num.begin()+doti+1,'.');
	}else{
		for(int i=0;i<e;i++)
			num.insert(num.begin()+1,'0');
		num.insert(num.begin()+2,'.');
	}

	for(int i=1;num[i]=='0'&&i<num.size()-1;i++){
		if(num[i+1]=='.')
			break;
		num.erase(i,1);
		i--;
	}
	if(num[0]=='+')
		num=num.substr(1);

	printf("%s",num.c_str());

	getchar();
	getchar();
	return 0;
}

//+1.000100E-01
//+1.234E+8
//+1.23400E-03
//+1.00000E+03
//+2.2E+03
//+1.23400E-03