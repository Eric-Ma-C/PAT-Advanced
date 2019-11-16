#include<stdio.h>
#include<algorithm>
using namespace std;

typedef struct gas{
	int dis;
	double price;
}gas;
gas g[505];

bool way[30005]={0};//已走的路
int tank[30005]={0};//油箱剩的油可跑的距离
bool cmp(gas g1,gas g2){
	return g1.price<g2.price;
}
int main(){
	int cmax,d,davg,n;
	scanf("%d %d %d %d",&cmax,&d,&davg,&n);
	for(int i=0;i<n;i++){
		scanf("%lf %d",&g[i].price,&g[i].dis);
	}
	int fulldis=cmax*davg;//加满油能跑的距离
	sort(g,g+n,cmp);//按价格排序
	double amount=0.0;
	for(int i=0;i<n;i++){
		int maxdis=g[i].dis+fulldis;
		int tmp=min(maxdis,d);
		while(way[tmp]&&tmp>g[i].dis)
			tmp--;

		int addlen=tmp-g[i].dis-tank[g[i].dis];//该站加的油能跑的距离
		if(addlen<=0)//该站不需要加油，因为它的前后有更便宜的
			continue;
		double addgas=addlen*1.0f/davg*1.0;
		int t=addlen;

		if(tank[g[i].dis]==0) tank[g[i].dis]=t--;
		else tank[g[i].dis]+=t;
		for(int j=g[i].dis+1;j<=tmp;j++){
			way[j]=true;//表示这公里走过了
			if(tank[j]==0)tank[j]=t--;
			else tank[j]+=t;//更新油量（用int距离表示避免精度损失）
		}
		amount+=g[i].price*addgas;
	}
	for(int i=1;i<=d;i++){
		if(way[i]==false){
			printf("The maximum travel distance = %.2f",(i-1)*1.0);
			return 0;
		}
	}
	printf("%.2lf",amount);

	getchar();
	getchar();
	return 0;
}