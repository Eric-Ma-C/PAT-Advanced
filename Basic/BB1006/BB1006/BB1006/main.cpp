#include<stdio.h>
using namespace std;
#include<string.h>


int main(){
	char a[10],b[10];
	char da,db;

	scanf("%s %c %s %c",a,&da,b,&db);
	
	int pa=0,pb=0;
	
	for(int i=0;a[i]!='\0';i++){
		if(a[i]==da){
			pa=pa*10+da-'0';
		}
	}
	for(int i=0;b[i]!='\0';i++){
		if(b[i]==db){
			pb=pb*10+db-'0';
		}
	}

	printf("%d",pa+pb);
	getchar();
	getchar();
	return 0;
}