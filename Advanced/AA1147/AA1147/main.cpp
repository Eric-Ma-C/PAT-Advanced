#include<stdio.h>
#include<algorithm>
using namespace std;
//34min
int lev[1005];
int m,n;
bool judgeMin(){
	for(int i=1;;i++){
		if(i*2<=n){
			if(lev[i]>lev[i*2])
				return false;
		}else{
			return true;
		}
		if(i*2+1<=n){
			if(lev[i]>lev[i*2+1])
				return false;
		}else{
			return true;
		}
	}
}
bool judgeMax(){
	for(int i=1;;i++){
		if(i*2<=n){
			if(lev[i]<lev[i*2])
				return false;
		}else{
			return true;
		}
		if(i*2+1<=n){
			if(lev[i]<lev[i*2+1])
				return false;
		}else{
			return true;
		}
	}
}
void post(int r){
	if(r*2<=n)
		post(r*2);
	if(r*2+1<=n)
		post(r*2+1);

	/*int first=1;
	while(first<=n){
		first=first<<1;
	}
	first=first>>1;
	if(r!=first)printf(" ");*/
	printf("%d",lev[r]);
	if(r!=1)printf(" ");
}
int main(){
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",lev+j);
		}
		bool maxheap=judgeMax();
		bool minheap=judgeMin();
		if(maxheap)printf("Max Heap\n");
		else if(minheap)printf("Min Heap\n");
		else printf("Not Heap\n");
		post(1);
		printf("\n");
	}

	getchar();
	getchar();
	return 0;
}

