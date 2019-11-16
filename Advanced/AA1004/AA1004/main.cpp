#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct point{
	int m,n,l;
}point;
int *p;//,*cache;
int *area;
//vector<point> pic;
point *pic;
int root(int i){

	int r=i;
	while(p[r]>=0){
		r=p[r];
	}

	while(p[i]>=0){
		int t=p[i];
		p[i]=r;
		i=t;
	}

	return r;
}
void unionp(int r1,int r2){

	p[r2]=r1;area[r1]+=area[r2];
	
}

bool isConnected(int i,int j){
	int len=abs(pic[i].m-pic[j].m)+abs(pic[i].n-pic[j].n)+abs(pic[i].l-pic[j].l);
	if(len==1)
		return true;

	return false;
}
int main(){
	int m,n,l,t;
	scanf("%d %d %d %d",&m,&n,&l,&t);
	pic=(point *)malloc(sizeof(point)*m*n*l);
	int tmp,num=0;
	for(int i=0;i<l;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				scanf("%d",&tmp);
				if(tmp==1){
					pic[num].m=j;pic[num].n=k;pic[num].l=i;
					num++;
				}
			}
		}
	}
	p=(int *)malloc(sizeof(int)*num);
	area=(int *)malloc(sizeof(int)*num);
	fill(p,p+num,-1);
	//fill(cache,cache+num,-1);
	fill(area,area+num,1);
	for(int i=0;i<num-1;i++){
		for(int j=i+1;j<num;j++)
			if(isConnected(i,j)){
				int r1=root(i);
				int r2=root(j);
				if(r1!=r2)
					unionp(r1,r2);
			}
	}
	int conut=0,areatotal=0;
	for(int i=0;i<num;i++){
		if(p[i]<0){
			if(area[i]>=t){
				areatotal+=area[i];
			}
		}
	}
	printf("%d",areatotal);

	getchar();
	getchar();
	return 0;
}