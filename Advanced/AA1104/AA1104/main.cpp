#include<stdio.h>

double a[100005];
double time[100005]={0};//不能用int，会溢出
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf",a+i);
		time[i]=(n-i)*1.0*(i+1);
	}
	double sum=0.0;
	for(int i=0;i<n;i++){
		sum+=a[i]*time[i];
	}
	printf("%.2f",sum);
	
	getchar();
	getchar();
	return 0;
}