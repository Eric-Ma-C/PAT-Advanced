#include<stdio.h>
#include<map>
using namespace std;
//21min
int main(){
	int m,n;
	scanf("%d %d",&m,&n);

	int num=n*m;
	int half=num/2;
	map<int,int> pix;int t;
	for(int i=0;i<num;i++){
		scanf("%d",&t);
		auto it=pix.find(t);
		if(it==pix.end()){
			pix[t]=1;
		}else{
			it->second++;
		}
	}

	for(auto it=pix.begin();it!=pix.end();it++){
		if(it->second>=half){
			printf("%d",it->first);
			break;
		}
	}
getchar();
getchar();
return 0;
}