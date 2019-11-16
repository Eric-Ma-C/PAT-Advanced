#include<stdio.h>
#include<iostream>
using namespace std;
//14min
char c1[10005];
char c2[10005];

int main(){

	cin.getline(c1,10002);
	cin.getline(c2,10002);

	for(int i=0;c1[i]!='\0';i++){
		bool ok=true;
		for(int j=0;c2[j]!='\0';j++){
			if(c2[j]==c1[i]){
				ok=false;break;
			}
		}
		if(ok)printf("%c",c1[i]);
	}
	getchar();
	getchar();
	return 0;
}