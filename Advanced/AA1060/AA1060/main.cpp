#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef struct num{
	ll a,b;
	bool posi;
}num;
void print(num n){
	if(n.a==0){printf("0");return;}
	if(n.b==0){printf("Inf");return;}

	if(n.posi==false)printf("(-");
	ll i=n.a/n.b;
	if(i>0) printf("%lld",i);
	if(i>0&&n.a%n.b!=0)printf(" ");
	if(n.a%n.b!=0)printf("%lld/%lld",n.a%n.b,n.b);
	if(n.posi==false)printf(")");
}
ll gcd(ll l1,ll l2){
	if(l2==0)return l1;
	return gcd(l2,l1%l2);
}
ll lcm(ll l1,ll l2){
	return l1/gcd(l1,l2)*l2;
}
num simple(num n){//»¯¼ò
	int d=gcd(n.a,n.b);
	n.a/=d;n.b/=d;
	return n;
}
num jia(num n1,num n2){
	ll tb=lcm(n1.b,n2.b);
	ll tp=gcd(n1.b,n2.b);

	if(n1.posi==false) n1.a=-n1.a;
	if(n2.posi==false) n2.a=-n2.a;
	ll ta=n2.b/tp*n1.a+n1.b/tp*n2.a;
	bool po=true;
	if(ta<0){po=false;ta=-ta;}
	ll d=gcd(tb,ta);
	num ans;ans.a=ta/d;ans.b=tb/d;ans.posi=po;
	ans=simple(ans);	
	return ans;
}
num cheng(num n1,num n2){
	ll ta=n1.a*n2.a;
	ll tb=n1.b*n2.b;
	bool po=n1.posi==n2.posi?true:false;
	num ans;ans.a=ta;ans.b=tb;ans.posi=po;
	ans=simple(ans);	
	return ans;
}
int main(){
	num n1,n2;
	scanf("%lld/%lld %lld/%lld",&n1.a,&n1.b,&n2.a,&n2.b);
	if(n1.a<0){n1.posi=false;n1.a=-n1.a;}
	else n1.posi=true;
	if(n2.a<0){n2.posi=false;n2.a=-n2.a;}
	else n2.posi=true;
	//string s1(c1);
	//string s2(c2);
	//n1.posi=s1.find('-')==s1.npos?true:false;
	//n2.posi=s2.find('-')==s2.npos?true:false;
	//int div1=s1.find('/');
	//int div2=s2.find('/');
	//int b1=n1.posi?0:1;
	//int b2=n2.posi?0:1;
	//n1.a=string2int(s1.substr(b1,div1-b1));
	//n2.a=string2int(s2.substr(b2,div2-b2));
	//n1.b=string2int(s1.substr(div1+1)); 
	//n2.b=string2int(s2.substr(div2+1));
	n1=simple(n1);
	n2=simple(n2);
	num a1=jia(n1,n2);
	num fun2=n2;fun2.posi=!fun2.posi;
	num a2=jia(n1,fun2);
	num a3=cheng(n1,n2);
	num daon2=n2;swap(daon2.a,daon2.b);
	num a4=cheng(n1,daon2);

	print(n1);printf(" + ");print(n2);printf(" = ");print(a1);printf("\n");
	print(n1);printf(" - ");print(n2);printf(" = ");print(a2);printf("\n");
	print(n1);printf(" * ");print(n2);printf(" = ");print(a3);printf("\n");
	print(n1);printf(" / ");print(n2);printf(" = ");print(a4);printf("\n");

	getchar();
	getchar();
	return 0;
}

