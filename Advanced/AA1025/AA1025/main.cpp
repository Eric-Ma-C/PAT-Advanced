#include<stdio.h>
//86min
int t[100005];
int visited[100005];
int main(){
	int n;
	scanf("%d",&n);int ok=0;
	for(int i=0;i<n;i++){
		scanf("%d",t+i);
		if(t[i]==i)
			ok++;
	}
	int count=0;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			count++;
			int begin=i;int tmp=begin;
			visited[begin]=true;
			tmp=t[tmp];
			while(tmp!=begin)
			{visited[tmp]=true;tmp=t[tmp];}
		}
	}
	if(t[0]==0)
		printf("%d",n-ok+(count-ok));
	else
		printf("%d",n-ok+(count-ok-1)-1);

	getchar();
	getchar();
	return 0;
}