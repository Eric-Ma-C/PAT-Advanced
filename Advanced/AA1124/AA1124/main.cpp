#include<stdio.h>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

int main(){
	int m,n,s;
	scanf("%d %d %d",&m,&n,&s);
	set<string> win;
	bool next=false;
	int count=0;
	for(int i=0;i<m;i++){
		char tmp[25];
		scanf("%s",tmp);

		if(i+1==s){
			win.insert(string(tmp));
			printf("%s\n",tmp);
			continue;
		}
		if(!next&&i+1>s)
			count++;

		if(next&&win.find(string(tmp))==win.end()){
			next=false;
			win.insert(string(tmp));
			printf("%s\n",tmp);
			count=0;
		}else if(!next&&count==n){
			if(win.find(string(tmp))!=win.end()){
				next=true;
				continue;
			}
			win.insert(string(tmp));
			printf("%s\n",tmp);
			count=0;
		}
	}

	if(win.size()==0)
		printf("Keep going...\n");
	getchar();
	getchar();
	return 0;
}

