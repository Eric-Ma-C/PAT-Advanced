#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int a[100005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	sort(a,a+n);
	int s1=0,s2=0;
	if(n%2==0){
		for(int i=0;i<n/2;i++){
			s1+=a[i];
		}
		for(int i=n/2;i<n;i++){
			s2+=a[i];
		}
		printf("%d %d",0,s2-s1);
	}else{
		for(int i=0;i<n/2;i++){
			s1+=a[i];
		}
		for(int i=n/2;i<n;i++){
			s2+=a[i];
		}
		printf("%d %d",1,s2-s1);
	}

	getchar();
	getchar();
	return 0;
}