#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    getchar();
 
    char c[100][257];
    char same[257]={0};
    for(int i=0;i<n;i++){
        fgets(c[i],257,stdin);
        c[i][strlen(c[i])-1]='\0';
        //gets_s(c[i]);
    }
    int t0=strlen(c[0])-1,t1=strlen(c[1])-1;
    for(;t0>=0,t1>=0,c[0][t0]==c[1][t1];
        t0--,t1--)
        ;
    strcpy(same,c[0]+t0+1);
 
 
    for(int i=2;i<n;i++){
        int j=strlen(c[i])-1;
        int s=strlen(same)-1;
        for(;s>=0,j>=0,same[s]==c[i][j];j--,s--)
            ;
		if(s>=0)
			strcpy(same,c[i]+j+1);
    }
 
    if(strlen(same)==0)
        printf("nai");
    else
        printf("%s",same);
 
 
getchar();
return 0;
} 


//#include<stdio.h>
//#include<iostream>
//#include<string.h>
//#include<algorithm>
//
//int main(){
//	int n;
//	scanf("%d",&n);
//	getchar();
//
//	char c[100][257];
//	int shortest=256;
//	for(int i=0;i<n;i++){
//		/*fgets(c[i],257,stdin);
//		c[i][strlen(c[i])-1]='\0';*/
//		//gets(c[i]);
//		std::cin.getline(c[i],257);
//
//		//reverse
//		int len=strlen(c[i]);
//		if(shortest>len)
//			shortest=len;
//		
//		std::reverse(c[i],c[i]+len);
//
//	}
//	int ans=0;
//	for(int i=0;i<shortest;i++){
//		char ch=c[0][i];
//		bool ok=true;
//		for(int j=1;j<n;j++){
//			if(c[j][i]!=ch){
//				ok=false;
//				break;
//			}
//		}
//
//		if(ok) ans++;
//		else break;
//	}
//
//	if(ans==0)
//		printf("nai");
//	else{
//		for(int i=ans-1;i>=0;i--)
//			printf("%c",c[0][i]);
//	}
//
//
//getchar();
//return 0;
//}