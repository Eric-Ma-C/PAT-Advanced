#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct item{
	int id,vg,tg;
}item;
vector<item> list;
int n,l,h;
int getrank(item it){
	if(it.vg>=h&&it.tg>=h)
		return 1;
	if(it.vg>=h&&it.tg<h)
		return 2;
	if(it.vg<h&&it.tg<h&&it.vg>=it.tg)
		return 3;
	else
		return 4;
}
bool cmp(item &i1,item &i2){
	int r1=getrank(i1);
	int r2=getrank(i2);
	if(r1!=r2)
		return r1<r2;
	else{
		if(i1.vg+i1.tg!=i2.vg+i2.tg)
			return i1.vg+i1.tg>i2.vg+i2.tg;
		else{
			if(i1.vg!=i2.vg)
				return i1.vg>i2.vg;
			else
				return i1.id<i2.id;
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&l,&h);
	int id,vg,tg;
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&id,&vg,&tg);
		if(vg<l||tg<l)continue;
		item it;
		it.id=id;it.vg=vg;it.tg=tg;
		list.push_back(it);
	}
	sort(list.begin(),list.end(),cmp);
	printf("%d\n",list.size());
	for(int i=0;i<list.size();i++)
		printf("%08d %d %d\n",list[i].id,list[i].vg,list[i].tg);

	getchar();
	getchar();
	return 0;
}