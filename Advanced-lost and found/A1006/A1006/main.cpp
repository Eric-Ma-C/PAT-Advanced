#include<stdio.h>
#include<stack>
using namespace std;
//24min
char getc(int a){
	if(a>=0&&a<=9)
		return a+'0';
	a-=10;
	return a+'A';
}
void prnt(int c){
	stack<char> s;
	while(c>0){
		int y=c%13;
		s.push(getc(y));
		c/=13;
	}
	int count=2-s.size();
	while(count>0){printf("0");count--;}

	while(!s.empty()){printf("%c",s.top());s.pop();}
}
int main(){
	int r,g,b;
	scanf("%d %d %d",&r,&g,&b);

	printf("#");
	prnt(r);
	prnt(g);
	prnt(b);


	getchar();
	getchar();
	return 0;
}