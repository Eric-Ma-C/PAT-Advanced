#include<stdio.h>

int getUp(int n){
	int t[4];
	t[0]=n/1000;n-=t[0]*1000;
	t[1]=n/100;n-=t[1]*100;
	t[2]=n/10;n-=t[2]*10;
	t[3]=n;

	for(int i=0;i<4;i++){
		for(int j=0;j<4-i-1;j++){
			if(t[j]>t[j+1]){
				int tt=t[j];
				t[j]=t[j+1];
				t[j+1]=tt;
			}
		}
	}
	int ans=t[0]*1000+t[1]*100+t[2]*10+t[3];
	return ans;
}
int getDown(int n){
	int t[4];
	t[0]=n/1000;n-=t[0]*1000;
	t[1]=n/100;n-=t[1]*100;
	t[2]=n/10;n-=t[2]*10;
	t[3]=n;

	for(int i=0;i<4;i++){
		for(int j=0;j<4-i-1;j++){
			if(t[j]<t[j+1]){
				int tt=t[j];
				t[j]=t[j+1];
				t[j+1]=tt;
			}
		}
	}
	int ans=t[0]*1000+t[1]*100+t[2]*10+t[3];
	return ans;
}
int main(){
	int n=0;
	scanf("%d",&n);

	int up=getUp(n);
	int down=getDown(n);

	int cha=-1;
	while(cha!=6174&&cha!=0){
		cha=down-up;
		printf("%04d - %04d = %04d\n",down,up,cha);
		up=getUp(cha);
	    down=getDown(cha);
	}
getchar();
getchar();
return 0;
}