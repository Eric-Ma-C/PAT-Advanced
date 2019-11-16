#include<stdio.h>
#include<string.h>
int main(){
	int gp,sp,kp;
	int ga,sa,ka;
	scanf("%d.%d.%d",&gp,&sp,&kp);
	scanf("%d.%d.%d",&ga,&sa,&ka);

	long p=gp*17*29L+sp*29L+kp;
	long a=ga*17*29L+sa*29L+ka;

	bool positive=true;
	long ans=a-p;
	if(ans<0){
		positive=false;
		ans=-ans;
	}
	int ansG=ans/(17*29);
	ans-=ansG*17*29;
	int ansS=ans/29;
	ans-=ansS*29;
	int ansK=ans;

	if(!positive){
	printf("-");
	}
	printf("%d.%d.%d",ansG,ansS,ansK);

getchar();
getchar();
return 0;
}