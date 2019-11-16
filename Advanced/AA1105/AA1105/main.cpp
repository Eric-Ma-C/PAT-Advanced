#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int a[10005]={0};
int mn[505][505];
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",a+i);
	}
	int m,n;
	for(int i=sqrt(1.0*N);i>0;i--){
		if(N%i==0){
			n=i;m=N/i;break;
		}
	}
	sort(a,a+N);
	int k=N-1,g=0;
	while(k>=0){
		for(int j=g;j<n-g&&k>=0;j++){
			mn[g][j]=a[k--];
		}
		for(int i=g+1;i<m-g-1&&k>=0;i++){
			mn[i][n-g-1]=a[k--];
		}
		for(int j=n-g-1;j>=g&&k>=0;j--){
			mn[m-g-1][j]=a[k--];
		}
		for(int i=m-g-2;i>g&&k>=0;i--){
			mn[i][g]=a[k--];
		}
		g++;
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d",mn[i][j]);
			if(j!=n-1)printf(" ");
			else printf("\n");
		}
	}
	getchar();
	getchar();
	return 0;
}