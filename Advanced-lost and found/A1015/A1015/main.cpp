#include<stdio.h>
#include<algorithm>
#define INF 0x3fffffff
//42min
bool visited[500]={0};
int team[500]={0};
int nteams[500]={0};
int ways[500]={0};


int dis[500]={0};
int roads[500][500]={0};
int city,m,c1,c2;

int getshort(){
	int ans=-1,minlen=INF;
	for(int i=0;i<city;i++){
		if(!visited[i]&&dis[i]<minlen){
			ans=i;minlen=dis[i];
		}
	}
	return ans;
}
int main(){
	
	scanf("%d %d %d %d",&city,&m,&c1,&c2);
	for(int i=0;i<city;i++){
		scanf("%d",team+i);
	}
	std::fill(roads[0],roads[500],INF);
	std::fill(dis,dis+500,INF);
	dis[c1]=0;nteams[c1]=team[c1];
	int t1,t2,len;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&t1,&t2,&len);
		roads[t1][t2]=len;roads[t2][t1]=len;
	}
	
	while(1){
		int ct=getshort();
		if(ct==-1)
			break;

		visited[ct]=true;
		for(int i=0;i<city;i++){
			if(!visited[i]&&roads[ct][i]!=INF&&dis[i]>dis[ct]+roads[ct][i]){
				ways[i]=1;
				dis[i]=dis[ct]+roads[ct][i];
				nteams[i]=nteams[ct]+team[i];
			}else if(!visited[i]&&roads[ct][i]!=INF&&dis[i]==dis[ct]+roads[ct][i]){
				ways[i]++;
				if(nteams[i]<nteams[ct]+team[i])
					nteams[i]=nteams[ct]+team[i];
			}
		}
	
	}

	printf("%d %d",ways[c2],nteams[c2]);
	getchar();
	getchar();
	return 0;
}