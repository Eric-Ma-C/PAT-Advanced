#include<stdio.h>

int main(){
	int num;char c;
	scanf("%d %c",&num,&c);
	int n=1;
	for(;n<100;n++){
		if(2*n*n-1>num)
			break;
	}
	n--;

	for(int i=0;i<2*n-1;i++){
		for(int j=0;j<2*n-1;j++){
			if((i<=n-1&&j>=i&&j+i<2*n-1)){
				printf("%c",c);
				if(i+j==2*n-2){
					printf("\n");
					break;
				}
			}else if(i>n-1&&j<=i&&j+i>=2*n-2){
				printf("%c",c);
				if(i==j){
					printf("\n");
					break;
				}
			}else
				printf(" ");

			if(j==2*n-2)
				printf("\n");

		}
	}

	printf("%d",num-2*n*n+1);
	getchar();
	getchar();
	return 0;
}