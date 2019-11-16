#include<stdio.h>
#include<string.h>
#include<algorithm>
//74min   if(r1!=r2)unionc(r1,r2);Ð´³Éif(r1!=r2)unionc(k,k2);µ¢ÎóÁË
bool way[1001][1001]={0};
bool tway[1001][1001]={0};
int city[1001];
int root(int i){
	for(;city[i]>0;i=city[i])
		;
	return i;
}
void unionc(int root1,int root2){
	if(city[root1]>city[root2]){
		city[root1]=root2;
	}else{
		if(city[root1]==city[root2])
			city[root1]+=city[root2];
		city[root2]=root1;
	}
}
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int c1,c2;
	for(int i=0;i<m;i++){
		scanf("%d %d",&c1,&c2);
		way[c1][c2]=1;
		way[c2][c1]=1;
	}
	int c,r1,r2;
	for(int i=0;i<k;i++){
		scanf("%d",&c);

		memcpy(tway,way,sizeof(bool)*1001*1001);
		for(int j=1;j<=n;j++){
			tway[c][j]=0;
			tway[j][c]=0;
		}
		std::fill(city,city+1001,-1);
		for(int k=1;k<=n;k++){
			for(int k2=k+1;k2<=n;k2++)
				if(tway[k][k2]){
					r1=root(k);
					r2=root(k2);
					if(r1!=r2)unionc(r1,r2);
				}
		}
		int num=0;
		for(int x=1;x<=n;x++){
			if(city[x]<0)
				num++;
		}
		printf("%d\n",num-2<0?0:num-2);
	}
	getchar();
	getchar();
	return 0;
}