#include<stdio.h>
//20min
void print(int i){
	if(i>0&&i<14)
		printf("S%d",i);
	else if(i-13>0&&i-13<14)
		printf("H%d",i-13);
	else if(i-26>0&&i-26<14)
		printf("C%d",i-26);
	else if(i-39>0&&i-39<14)
		printf("D%d",i-39);
	else if(i-52>0&&i-52<55)
		printf("J%d",i-52);
}

int main(){
	int n;
	scanf("%d",&n);
	int t[57];int order[57];
	for(int i=1;i<=54;i++){
		t[i]=i;
		scanf("%d",order+i);
	}
	int tmp[57];
	for(int i=0;i<n;i++){
		for(int j=1;j<=54;j++){
			tmp[order[j]]=t[j];
		}
		for(int j=1;j<=54;j++){
			t[j]=tmp[j];
		}
	}

	for(int j=1;j<=54;j++){
			print(t[j]);
			if(j!=54)printf(" ");
	}


	getchar();
	getchar();
	return 0;
}