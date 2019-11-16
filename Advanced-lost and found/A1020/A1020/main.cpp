#include<stdio.h>
//18min
int main(){
	int n;
	scanf("%d",&n);
	int t;int cur=0;int time=0;
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		if(t-cur<0)time+=(cur-t)*4;
		else time+=6*(t-cur);

		time+=5;cur=t;
	}
	printf("%d",time);

	getchar();
	getchar();
return 0;
}