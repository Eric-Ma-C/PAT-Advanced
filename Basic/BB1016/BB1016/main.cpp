#include<stdio.h>

int main(){
	int c1,c2;
	scanf("%d %d",&c1,&c2);

	double during=(c2-c1)/100.0;
	int hour,minute,seconds;

	hour=during/3600;
	during-=hour*3600;
	minute=during/60;
	seconds=(int)(during-minute*60+0.5);

	printf("%02d:%02d:%02d",hour,minute,seconds);
	getchar();
	getchar();
	return 0;
}