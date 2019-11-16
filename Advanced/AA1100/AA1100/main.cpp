#include<stdio.h>
#include<iostream>
#include<string>
#include<sstream>
#include<map>
using namespace std;
//47min
char low[][5]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
char heigh[][5]={"tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
int string2int(string s){
	int i;
	stringstream st(s);
	st>>i;
	return i;
}
int main(){
	int n;
	scanf("%d",&n);

	map<string,int> marsl;
	map<string,int> marsh;
	marsl["tret"]=0;
	for(int i=0;i<12;i++){
		marsl[string(low[i+1])]=i+1;
		marsh[string(heigh[i])]=i+1;
	}
	getchar();
	for(int i=0;i<n;i++){
		char tmp[20];
		cin.getline(tmp,20);
		if(tmp[0]>='0'&&tmp[0]<='9'){
			int e=string2int(string(tmp));
			int h=e/13;
			int l=e%13;
			if(h>0)printf("%s",heigh[h-1]);
			if(h>0&&l!=0)printf(" ");
			if(h==0||l!=0)printf("%s\n",low[l]);
			else printf("\n");
		}else{
			string m(tmp),ml,mh;
			int j=m.find(' ');
			if(j!=m.npos){ 
				mh=m.substr(0,j);
				ml=m.substr(j+1);
			}else{
				ml=m;
			}
			int el,eh;
			if(mh.size()>0)eh=marsh[mh];
			else eh=0;

			if(marsl.find(ml)!=marsl.end())el=marsl[ml];
			else {el=0;eh=marsh[ml];}
	
			int e=eh*13+el;
			printf("%d\n",e);
		}
	}
	getchar();
	getchar();
	return 0;}


