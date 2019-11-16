#include<stdio.h>
#include<string.h>
#include<math.h>
//120min


//测试用例:
//s9jix hj 1 36
//对应输出应该为:
//2792614
//测试用例:
//10 aaaaaaaaaa 2 15
//对应输出应该为:
//411893136160
//你的输出为:
//-423724256
int getn(char c){
	if(c>='0'&&c<='9')
		return c-'0';
	if(c>='a'&&c<='z')
		return c-'a'+10;

	return -1;
}
int main(){
	char n1[11],n2[11];
	int t,r;
	scanf("%s %s %d %d",&n1,&n2,&t,&r);

	char n[11],tar[11];
	if(t==1){
		strcpy(n,n1);
		strcpy(tar,n2);
	}else{
		strcpy(n,n2);
		strcpy(tar,n1);
	}
	long long dec=0;
	for(int i=0;i<strlen(n);i++){
		dec*=r;
		dec+=getn(n[i]);
	}
	long long ra,rmin,rmax;bool find=0;

	int len=strlen(tar);
	double y=(len-1)==0?1:len-1;
	rmax=pow((dec),1.0/y);
	rmin=pow((dec+1),1.0/len);
	long long sum=0;long long s=0;
	for(;;){
		if(rmax-rmin<0){
			break;
		}

		ra=(rmin+rmax)/2;
		sum=0;s=0;
		for(int i=0;i<len;i++){
			s=getn(tar[i]);
			
			sum*=ra;
			sum+=s;
		}
		if(sum<dec){
			rmin=ra+1;
		}else if(sum>dec){
			rmax=ra-1;
		}else{
			find=1;
			break;
		}
	}

	if(find){printf("%lld",ra);}
	else printf("Impossible");


	getchar();
	getchar();
	return 0;
}