#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
//120min 注意题目细节，思路要清晰
int n,m,k,q;
int take[1001];
int done[1001]={0};
queue<int> win[21];
int work[21]={0};
int searchq(){
	int min=m,mini=0;
	for(int i=1;i<=n;i++){
		if(win[i].size()<min){
			min=win[i].size();
			mini=i;
		}
	}
	if(min==m)
		return -1;
	else
		return mini;
}
int freewin(){
	int num=0;
	for(int i=1;i<=n;i++){
		if(win[i].size()<m)
			num++;
	}
	return num;
}
bool gomin(int curt){
	for(int i=1;i<=n;i++){
		if(work[i]==0)
			continue;
		work[i]--;
		if(work[i]==0){
			int c=win[i].front();
			done[c]=curt;
			win[i].pop();
			if(win[i].size()>0)
				work[i]=take[win[i].front()];
			else
				work[i]=0;//nobody in front of the window
		}
	}
	return 1;
}
void printt(int c){
	int mins=done[c];
	if(mins==-1){printf("Sorry\n");return;}
	int hour=mins/60;
	int min=mins%60;

	printf("%02d:%02d\n",hour+8,min);
}
int main(){
	scanf("%d %d %d %d",&n,&m,&k,&q);

	for(int i=1;i<=k;i++){
		scanf("%d",take+i);	
	}
	int curc=1;
	for(;curc<=n*m&&curc<=k;curc++){
		win[(curc-1)%n+1].push(curc);
	}
	for(int i=1;i<=n&&i<=k;i++)
		{work[i]=take[i];}

	fill(done,done+1001,-1);
	int w=0;int freenum=0;
	for(int t=1;t<=60*9;t++){//serve to 17:00
		gomin(t);
		freenum=freewin();
		if(freenum==0){
			continue;
		}
		for(int j=0;j<freenum;j++){
			w=searchq();
			if(w!=-1){
				win[w].push(curc);
				curc++;
			}
		}
	}
	for(int i=1;i<=n;i++){//after 17:00
		if(work[i]>0){
			if(take[win[i].front()]>work[i])
				done[win[i].front()]=9*60+work[i];
		}
	}

	int tmp;
	for(int i=0;i<q;i++){
		scanf("%d",&tmp);
		printt(tmp);
	}
	getchar();
	getchar();
	return 0;
}