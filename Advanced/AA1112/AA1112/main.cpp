#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//33min
typedef struct item{
	int id;
	char c;
}item;
map<char,item> m;
bool cmp(item i1,item i2){
	return i1.id<i2.id;
}
int main(){
	int k;
	scanf("%d",&k);
	char c[1100];
	scanf("%s",c);
	int len=strlen(c);
	int index=0;
	for(int i=0;i<len;){
		int count=0;
		for(int j=i;j<len&&c[j]==c[i];j++)
			count++;
		bool broken=false;
		if(count%k==0)broken=true;

		if(m.find(c[i])==m.end()){
			item it;
			it.c=c[i];
			if(broken) it.id=index++;
			else it.id=-1;
			m[c[i]]=it;
		}else{
			if(m[c[i]].id>0&&!broken){
				m[c[i]].id=-1;
			}
		}

		i+=count;
	}
	char ac[1100]={0};
	int tmp=0;
	for(int i=0;i<len;){
		int count=0;
		for(int j=i;j<len&&c[j]==c[i];j++)
			count++;

		if(m[c[i]].id<0){
			for(int j=0;j<count;j++)
				ac[tmp++]=c[i];
		}else{
			for(int j=0;j<count/k;j++)
				ac[tmp++]=c[i];
		}
		i+=count;
	}
	vector<item> ans;
	for(auto it=m.begin();it!=m.end();it++){
		if(it->second.id>=0)
			ans.push_back(it->second);
	}
	sort(ans.begin(),ans.end(),cmp);
	for(int i=0;i<ans.size();i++){
		printf("%c",ans[i].c);
	}
	printf("\n%s",ac);

	getchar();
	getchar();
	return 0;
}