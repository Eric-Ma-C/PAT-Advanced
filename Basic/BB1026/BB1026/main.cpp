#include<stdio.h>

int main(){
	int size;char c;
	scanf("%d %c",&size,&c);

	int col=(int)(size/2.0+0.5);
	for(int i=0;i<col;i++){
		for(int j=0;j<size;j++){
			if(j==size-1)
				printf("%c\n",c);
			else if(i==0||i==col-1||j==0)
				printf("%c",c);
			else
				printf(" ");
		}
	
	}

getchar();
getchar();
return 0;
}