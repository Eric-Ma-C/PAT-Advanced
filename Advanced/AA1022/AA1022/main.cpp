#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
//50min
int a[1005],r[1005];
void getroot(int ri,int b,int e){
	if(b>e)return;
	if(b==e){
		r[ri]=a[b];
		return;
	}
	int i=1,all=e-b+1;
	for(;pow(2.0,i)-1<=all;i++)
		;
	int h=i-1;
	int lastlev=all-(pow(2.0,h)-1);//>=0
	int maxleft=pow(2.0,h-1);
	int left=(all-1-lastlev)/2;
	int right=left;
	if(lastlev>=maxleft){left+=maxleft;right+=lastlev-maxleft;}
	else {left+=lastlev;}

	r[ri]=a[b+left];
	getroot(ri*2+1,b,b+left-1);
	getroot(ri*2+2,b+left+1,e);
} 
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	sort(a,a+n);
	fill(r,r+n,-1);
	getroot(0,0,n-1);
	for(int i=0;i<n-1;i++)
		printf("%d ",r[i]);
	printf("%d",r[n-1]);

	getchar();
	getchar();
return 0;
}