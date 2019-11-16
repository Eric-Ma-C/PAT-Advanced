#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
typedef struct player{
	int hour,min,sec;
	int servesec;
	int playing;//min
	bool vip;
}player;
typedef struct table{
	bool available;
	bool vip;
	int remainsec,players;
}table;
int n,k,m;
table tables[105];
vector<player> list;
vector<int> que;
int getsec(player p){
	return p.hour*3600+p.min*60+p.sec;
}
bool cmp(player &p1,player &p2){
	return getsec(p1)<getsec(p2);
}
bool cmp2(player &p1,player &p2){
	return p1.servesec<p2.servesec;
}
void tableAvailable(int *all,int *vip){
	*all=0,*vip=0;
	for(int i=1;i<=k;i++){
		if(tables[i].available){
			(*all)++;
			if(tables[i].vip)
				(*vip)++;
		}
	}
}
int gettable(){
	for(int i=1;i<=k;i++){
		if(tables[i].available)
			return i;
	}
	return -1;
}
int getviptable(){
	for(int i=1;i<=k;i++){
		if(tables[i].vip&&tables[i].available)
			return i;
	}
	return -1;
}
void refreshTable(){
	for(int i=1;i<=k;i++){
		if(!tables[i].available){
			tables[i].remainsec--;
			if(tables[i].remainsec==0){
				tables[i].players++;
				tables[i].available=true;
			}
		}
	}
}
int nextvip(){
	for(int i=0;i<que.size();i++){
		if(list[que[i]].vip){
			int t=que[i];
			que.erase(que.begin()+i);
			return t;
		}
	}
	return -1;
}
int nextplayer(){
	if(que.size()>0){
		int t=que[0];
		que.erase(que.begin());
		return t;
	}
	return -1;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		player p;int tag;
		scanf("%d:%d:%d %d %d",&p.hour,&p.min,&p.sec,&p.playing,&tag);
		if(tag==1)p.vip=true;
		else p.vip=false;

		if(p.playing>120)p.playing=120;

		p.servesec=0;
		list.push_back(p);
	}
	scanf("%d %d",&k,&m);
	for(int i=1;i<=k;i++){
		tables[i].available=true;
		tables[i].vip=false;
		tables[i].players=0;
		tables[i].remainsec=0;
	}
	for(int i=0;i<m;i++){
		int t;
		scanf("%d",&t);
		tables[t].vip=true;
	}

	sort(list.begin(),list.end(),cmp);
	int nextin=getsec(list[0]);
	int next=0;
	int h0800=8*3600,h2100=21*3600;
	for(int i=h0800;i<h2100;i++){
		refreshTable();
		if(i==nextin){//someone comes
			que.push_back(next);
			if(next==n-1){nextin=-1;}
			else {next++;nextin=getsec(list[next]);	}
		}
		int all,vip;
		tableAvailable(&all,&vip);
		int vipserved=0;
		int id;
		while(vip--&&(id=nextvip())!=-1){
			int v=getviptable();
			tables[v].remainsec=list[id].playing*60;
			tables[v].available=false;
			list[id].servesec=i;
			vipserved++;
		}
		all-=vipserved;
		while(all--&&(id=nextplayer())!=-1){
			int t=gettable();
			tables[t].remainsec=list[id].playing*60;
			tables[t].available=false;
			list[id].servesec=i;
		}
	}
	//last second
	for(int i=1;i<=k;i++){
		if(!tables[i].available){	
			tables[i].players++;	
		}
	}
	sort(list.begin(),list.end(),cmp2);
	for(int i=0;i<n;i++){
		player p=list[i];
		if(p.servesec==0)
			continue;
		int h,m,s;
		h=p.servesec/3600;m=(p.servesec-3600*h)/60;
		s=p.servesec-3600*h-60*m;
		int wait=floor((p.servesec-getsec(p))/60.0+0.5f);
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",p.hour,p.min,p.sec,h,m,s,wait);

	}
	for(int i=1;i<=k;i++){
		printf("%d",tables[i].players);
		if(i!=k)printf(" ");
	}

	getchar();
	getchar();
	return 0;
}