#include<stdio.h>
#include<string.h>
//30min
int main(){
	char n[22]={0},n2[22]={0};
	bool visited[22]={0};
	scanf("%s",n);

	int len=strlen(n);
	int carry=0;
	for(int i=len-1;i>=0;i--){
		int t=n[i]-'0';
		int tmp=t*2+carry;
		carry=tmp>9?1:0;
		int t2=tmp-(carry?10:0);
		n2[i]=t2+'0';
	}
	if(carry){
		printf("No\n1%s",n2);
		return 0;
	}
	int num=0;
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			if(n2[j]==n[i]&&!visited[j]){
				visited[j]=true;
				num++;
				break;
			}
		}
	}
	if(num==len)
		printf("Yes\n");
	else
		printf("No\n");
	printf("%s",n2);
	

	getchar();
	getchar();
	return 0;
}