#include<stdio.h>
#include<string.h>

int main(){
	char c1[1005],c2[1005];
	bool visited[1005]={0};
	scanf("%s%s",c1,c2);
	int len1=strlen(c1);
	int len2=strlen(c2);
	int num=0;
	for(int i=0;i<len2;i++){
		for(int j=0;j<len1;j++){
			if(c2[i]==c1[j]&&!visited[j]){
				visited[j]=true;
				num++;
				break;
			}
		}
	}
	if(num==len2){
		printf("Yes %d",len1-num);
	}else{
		printf("No %d",len2-num);
	}


	getchar();
	getchar();
	return 0;
}