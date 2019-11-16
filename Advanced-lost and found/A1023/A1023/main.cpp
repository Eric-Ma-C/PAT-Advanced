#include<stdio.h>
#include<math.h>
//59min
int getmax(double* a){
	if(a[0]>a[1]&&a[0]>a[2]){
		return 0;
	}
	if(a[1]>a[0]&&a[1]>a[2]){
		return 1;
	}
	if(a[2]>a[1]&&a[2]>a[0]){
		return 2;
	}
	return 0;
}

void pr(int i){
if(i==0)
	printf("W");
if(i==1)
	printf("T");
if(i==2)
	printf("L");
}
int main(){
	double a[3],b[3],c[3];

	scanf("%lf %lf %lf",&a[0],&a[1],&a[2]);
	scanf("%lf %lf %lf",&b[0],&b[1],&b[2]);
	scanf("%lf %lf %lf",&c[0],&c[1],&c[2]);

	int ma=getmax(a);
	int mb=getmax(b);
	int mc=getmax(c);

	pr(ma);
	printf(" ");
	pr(mb);
	printf(" ");
	pr(mc);
	double f=(a[ma]*b[mb]*c[mc]*0.65-1.0)*2.0;
	//f=floor(f*1000+0.5)/1000.0f;

	printf(" %.2lf",f+1e-8);

	getchar();
	getchar();
	return 0;
}