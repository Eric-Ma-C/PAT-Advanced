#include<stdio.h>
//60min
int gcd(int a,int b){
	if(b==0)
		return a;

	return gcd(b,a%b);
}
void simple(int *a,int* b){
	if(*a==0||*b==0)
		return;

	int g=gcd(*a,*b);
	*a/=g;
	*b/=g;
}
bool getSum(int a1,int b1,int a2,int b2,int* a3,int* b3){
	*a3=a1*b2+a2*b1;
	*b3=b1*b2;

	bool positive=true;
	if(*a3<0){
		*a3=-*a3;
		positive=false;
	}

	simple(a3,b3);

	if(!positive){
		*a3=-*a3;
	}
	return positive;
}
int main(){
	int n;
	scanf("%d",&n);

	int a[100][2];
	for(int i=0;i<n;i++){
		scanf("%d/%d",a[i]+0,a[i]+1);
	}
	int aa=0,bb=1;
	for(int i=0;i<n;i++){
		getSum(aa,bb,a[i][0],a[i][1],&aa,&bb);		
	}
	if(aa==0){
		printf("0");
		return 0;
	}

	if(aa<0){
		printf("-");
		aa=-aa;
	}
	int c=aa/bb;
	if(c!=0){
	   printf("%d",c);
	   aa-=c*bb;
	}
	if(aa!=0){
		if(c!=0)
			printf(" ");
		printf("%d/%d",aa,bb);
	}

	getchar();
	getchar();
	return 0;
}