#include<stdio.h>
#include<string.h>
//30min
int main(){
	char s[82];
	scanf("%s",s);
	int n=strlen(s);

	int max=0;
	for(int t2=3;t2<=n;t2++){
		int k=(n+2-t2)/2;
		if(k>max&&k<=t2)
			max=k;
	}
	int n2=n+2-2*max;
	for(int i=0;i<max;i++){
		for(int j=0;j<n2;j++){
			if(j==0)printf("%c",s[i]);
			else if(j==n2-1)printf("%c\n",s[n-i-1]);
			else if(i==max-1){
				printf("%c",s[max+j-1]);
			}else printf(" ");
		} 
	}
	getchar();
	getchar();
	return 0;
}