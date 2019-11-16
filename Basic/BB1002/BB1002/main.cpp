#include<stdio.h>
//20min
int main(){
	int n;
	scanf("%d",&n);

	int a[1002];

	int a1=0,a2=0,a3=0,a4=0,a5=0;
	bool posi=true;int num2=0,num4=0;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);

		if(a[i]%10==0){
			a1+=a[i];
		}

		if(a[i]%5==1){
			if(posi){
				a2+=a[i];
			}else{
				a2-=a[i];
			}
			num2++;
			posi=!posi;
		}
		if(a[i]%5==2){
			a3++;
		}
		if(a[i]%5==3){
			a4+=a[i];
			num4++;
		}
		if(a[i]%5==4){
			if(a[i]>a5)
				a5=a[i];
		}
	}

	if(a1==0)
		printf("N ");
	else
		printf("%d ",a1);

	if(num2==0)
		printf("N ");
	else
		printf("%d ",a2);

	if(a3==0)
		printf("N ");
	else
		printf("%d ",a3);

	if(num4==0)
		printf("N ");
	else
		printf("%.1f ",1.0f*a4/num4);

	if(a5==0)
		printf("N");
	else
		printf("%d",a5);


getchar();
getchar();
return 0;
}