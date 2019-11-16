#include<stdio.h>
//
int n[10002]={0};
int k;
int getcsum(int s,int e,int *i1,int *i2){
	if(e-s<0){return 0;}
	if(e==s) return n[e]>0?n[e]:0;
	if(s+1==e) return n[e]+n[s]>0?n[e]+n[s]:0;


	int t=(e+s)/2+1;
	int s1=n[t],st=0,s2=n[t-1];
	*i1=t-1;*i2=t;
	for(int i=t;i<=e;i++){
		st+=n[i];
		if(st>s1)
		{s1=st;*i2=i;}
	}
	st=0;
	for(int i=t-1;i>=s;i--){
		st+=n[i];
		if(st>s2)
		{s2=st;*i1=i;}
	}
	return s1+s2;
}
int getmsum(int s,int e,int *i1,int *i2){
	if(e<s) {*i1=10000;*i2=10000;return 0;}
	if(e==s){*i1=e;*i2=e;return n[e]>0?n[e]:0;}

	int b1,e1,b2,e2,b3,e3;
	int s1=getmsum(s,(e+s)/2,&b1,&e1);
	int s2=getmsum((e+s)/2+1,e,&b2,&e2);
	int s3=getcsum(s,e,&b3,&e3);

	if(s1>=s2&&s1>=s3){
		if(s1==s3&&b3<b1){*i1=b3;*i2=e3;return s1;}
		else{*i1=b1;*i2=e1;return s1;}
	}
	if(s2>=s1&&s2>=s3){
		if(s2==s1){*i1=b1;*i2=e1;return s2;}
		if(s2==s3){*i1=b3;*i2=e3;return s2;}
		else{*i1=b2;*i2=e2;return s2;}
	}
	if(s3>=s2&&s3>=s1){
		if(s3==s1&&b1<b3){*i1=b1;*i2=e1;return s3;}
		else{*i1=b3;*i2=e3;return s3;}
	}
	return 0;
}
int main(){
	scanf("%d",&k);
	bool alln=1;
	for(int i=0;i<k;i++){
		scanf("%d",n+i);if(n[i]>0) alln=0;}

	if(alln){
	printf("%d %d %d",0,n[0],n[k-1]);
	return 0;
	}
	int maxsum=0;
	int beg=0,end=0;
	
	maxsum=getmsum(0,k-1,&beg,&end);
	printf("%d %d %d",maxsum,n[beg],n[end]);

	getchar();
	getchar();
	return 0;
}