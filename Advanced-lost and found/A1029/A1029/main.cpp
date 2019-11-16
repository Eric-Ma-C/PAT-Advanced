#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define BEGIN_SEC 28800
#define END_SEC 61200
typedef struct cus{
	int hour,min,sec;//T
	int take;//P  minute
	int wait;//second
}cus;
int n,k;
int win[100]={0};//the remaining time(seconds) to finish work
cus* l;
bool cmp(cus c1,cus c2){
	if(c1.hour!=c2.hour){
		return c1.hour<c2.hour;
	}else{
		if(c1.min!=c2.min)
			return c1.min<c2.min;
		else
			return c1.sec<c2.sec;
	}	
}
int getWaitSec(int t,int c){//cal wait time in seconds
	int begin=l[c].hour*3600+l[c].min*60+l[c].sec;
	return t-begin;
}
bool getWin(int *curk,int t){
	for(int w=0;w<k;w++){
		if(win[w]==0&&*curk<n){
			int begin=l[*curk].hour*3600+l[*curk].min*60+l[*curk].sec;
			if(begin>END_SEC)
				return false;
			if(begin>t)//not arrive
				break;
			win[w]=l[*curk].take*60;
			l[*curk].wait=getWaitSec(t,*curk);
			(*curk)++;
		}
	}
	return true;
}
int main(){
	scanf("%d %d",&n,&k);
	l=(cus*)malloc(sizeof(cus)*n);
	for(int i=0;i<n;i++){
		scanf("%d:%d:%d %d",&l[i].hour,&l[i].min,&l[i].sec,&l[i].take);
	}
	std::sort(l,l+n,cmp);

	int curk=0;
	for(;curk<k&&curk<n;curk++){//init
		int begin=l[curk].hour*3600+l[curk].min*60+l[curk].sec;
		if(begin>BEGIN_SEC)//not arrive
			break;
		win[curk]=l[curk].take*60;
		l[curk].wait=getWaitSec(BEGIN_SEC,curk);
	}
	for(int t=BEGIN_SEC+1;curk<n;t++){//second by second
		for(int i=0;i<k;i++){
			if(win[i]>0)
				win[i]--;	
		}
		if(!getWin(&curk,t))
			break;
	}
	long long sum=0;
	for(int i=0;i<curk;i++){
		sum+=l[i].wait;
	}
	double ave=sum*1.0f/curk/60.0f;
	printf("%.1f",ave);

	return 0;
}