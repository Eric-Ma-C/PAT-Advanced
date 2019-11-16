#include<stdio.h>
//16min
bool tag[1000]={0};
char id[1000][11];
char pwd[1000][11];
int main(){
	int n,m;
	scanf("%d",&n);
	m=0;
	for(int i=0;i<n;i++){
		scanf("%s %s",id[i],pwd[i]);

		for(int j=0;pwd[i][j]!='\0';j++){
			if(pwd[i][j]=='1')
				{pwd[i][j]='@';tag[i]=true;}
			if(pwd[i][j]=='0')
				{pwd[i][j]='%';tag[i]=true;}
			if(pwd[i][j]=='l')
				{pwd[i][j]='L';tag[i]=true;}
			if(pwd[i][j]=='O')
				{pwd[i][j]='o';tag[i]=true;}
		}
		if(tag[i]==true)
				m++;
	}
	if(m!=0)
	printf("%d\n",m);
	else if(n!=1)
		printf("There are %d accounts and no account is modified",n);
	else
		printf("There is 1 account and no account is modified",n);

	for(int i=0;i<n;i++){
		if(tag[i]){
			printf("%s %s\n",id[i],pwd[i]);
		}
	}

getchar();
getchar();
return 0;
}