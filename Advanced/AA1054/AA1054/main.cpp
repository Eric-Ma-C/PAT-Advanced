#include<stdio.h>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;


int string2int(string s){
	int a;
	stringstream stream(s);
	stream >> a;
	return a;
}
string int2string(int a){
	stringstream stream;
	stream << a;
	string s=stream.str();
	while(s.size()<4){
		s.insert(s.begin(),'0');
	}
	return s;
}
bool cmp(char c1,char c2){
	return c1>c2;
}
int main(){
	int n;
	scanf("%d",&n);

	do{
		string s1=int2string(n);
		string s2=s1;
		sort(s1.begin(),s1.end());
		sort(s2.begin(),s2.end(),cmp);
		if(s1==s2){
			printf("%04d - %04d = 0000",n,n);
			return 0;
		}
		int n1=string2int(s1);
		int n2=string2int(s2);
		n=n2-n1;
		printf("%04d - %04d = %04d\n",n2,n1,n);

	}while(n!=6174);

	getchar();
	getchar();
	return 0;
}