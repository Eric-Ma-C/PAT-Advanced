#include<stdio.h>
#include<algorithm>
#include<stack>
using namespace std;

int main(){
	int m,n,k;
	scanf("%d %d %d",&m,&n,&k);
	int t[1005];
	bool v[1005];
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			scanf("%d",t+j);
		}
		fill(v+1,v+n+1,false);
		stack<int> s;int tag=true;
		for(int j=0;j<n;j++){

			if(s.size()>0&&s.top()==t[j]){	
				s.pop();
			}else{
				if(v[t[j]]==true)
				{printf("NO\n");tag=0;break;}

				if(s.size()>=m)
				{printf("NO\n");tag=0;break;}

				v[t[j]]=true;
				for(int a=1;a<t[j];a++){
					if(!v[a]){
						v[a]=true;
						s.push(a);
					}
				}
				if(s.size()>m-1)
				{printf("NO\n");tag=0;break;}
			}
		}
		if(tag)
			printf("YES\n");
	}
	getchar();
	getchar();
	return 0;
}