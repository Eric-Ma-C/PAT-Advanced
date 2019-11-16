#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
typedef struct flo{
	int e;
	string num;
}flo;
int  n;
flo getstandard(char* ori){
	string s;
	int beginzero=0,zhshu=0;bool nopos=true;int dot=-1;
	for(int i=0;ori[i]!='\0';i++){
		if(ori[i]=='.')
		{dot=i;continue;}
		if(nopos&&ori[i]=='0')
		{beginzero++;continue;}


		nopos=false;
		s+=ori[i];
	}
	if(dot<0)
		zhshu=strlen(ori)-beginzero;
	else{
		zhshu=dot-beginzero;
	}
	if(s.size()==0)//0
		zhshu=0;

	while(s.size()<n)
		s+='0';
	s=s.substr(0,n);

	flo f;
	f.num=s;f.e=zhshu;
	return f;
}
void print(flo f){

	printf("0.%s*10^%d",f.num.c_str(),f.e);
}
int main(){

	char a[105],b[105];
	scanf("%d %s %s",&n,a,b);

	flo f1=getstandard(a);
	flo f2=getstandard(b);

	if(f1.e==f2.e&&f1.num==f2.num){
		printf("YES ");
		print(f1);
	}else{
		printf("NO ");
		print(f1);
		printf(" ");
		print(f2);
	}

	getchar();
	getchar();
	return 0;
}