#include<stdio.h>
#include<algorithm>
using namespace std;

typedef struct user{
	int rank,id,total,fullnum;
	int score[8];
	bool show;
}user;
int full[8];
user list[10005];
bool cmp(user& u1,user& u2){
	if(u1.total!=u2.total)
		return u1.total>u2.total;
	else{
		if(u1.fullnum!=u2.fullnum)
			return u1.fullnum>u2.fullnum;
		else{
			return u1.id<u2.id;
		}
	}
}
int main(){
	int n,k,m;
	scanf("%d %d %d",&n,&k,&m);

	for(int i=1;i<=k;i++){
		scanf("%d",full+i);
	}
	for(int i=1;i<=n;i++){
		list[i].id=i;
		list[i].rank=0;
		list[i].total=0;
		list[i].fullnum=0;
		list[i].show=false;
		for(int j=1;j<=k;j++)
			list[i].score[j]=-2;
	}
	for(int i=1;i<=m;i++){
		int id,pid,sc;
		scanf("%d %d %d",&id,&pid,&sc);

		if(sc>list[id].score[pid]){
			if(sc==full[pid])
				list[id].fullnum++;
			if(sc>=0)
				list[id].show=true;
			
			list[id].score[pid]=sc;
		}
	}
	for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(list[i].score[j]>0)
					list[i].total+=list[i].score[j];
			}
	}
	sort(list+1,list+n+1,cmp);
	int lastt=list[1].total;
	int rank=1;
	for(int i=1;i<=n;i++){
		if(lastt!=list[i].total)
			rank=i;
		list[i].rank=rank;
		lastt=list[i].total;
	}
	for(int i=1;i<=n;i++){
		if(!list[i].show)
			continue;
		printf("%d %05d %d ",list[i].rank,list[i].id,list[i].total);
		for(int j=1;j<=k;j++){
			if(list[i].score[j]==-2)printf("-");
			else if(list[i].score[j]==-1)printf("0");
			else printf("%d",list[i].score[j]);
			if(j!=k)
				printf(" ");
		}
		printf("\n");
	}
	getchar();
	getchar();
	return 0;
}