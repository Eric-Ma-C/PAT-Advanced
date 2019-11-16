#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int size;
	scanf("%d",&size);
	int *grade=(int*)malloc(sizeof(int)*size);
	for(int i=0;i<size;i++){
		scanf("%d",grade+i);
	}
	int size2;
	scanf("%d",&size2);
	int *grade2=(int*)malloc(sizeof(int)*size2);
	int *ans=(int*)malloc(sizeof(int)*size2);
	for(int i=0;i<size2;i++){
		scanf("%d",grade2+i);
	}
	memset(ans,0,sizeof(int)*size2);
	for(int i=0;i<size;i++){
		for(int j=0;j<size2;j++){
			if(grade2[j]==grade[i])
				ans[j]++;
		}
	}

	for(int j=0;j<size2-1;j++){
		printf("%d ",ans[j]);
	}
	printf("%d",ans[size2-1]);
getchar();
getchar();
return 0;
}