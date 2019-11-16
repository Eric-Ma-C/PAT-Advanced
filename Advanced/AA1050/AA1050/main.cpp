#include<stdio.h>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
//22min
map<string,vector<int> > stu;

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int id,num;char name[7];
	for(int i=0;i<k;i++){
		scanf("%d %d",&id,&num);
		for(int j=0;j<num;j++){
			scanf("%s",name);
			string sn(name);
			if(stu.find(sn)==stu.end()){
				vector<int> cl;
				stu[sn]=cl;
			}
			stu[sn].push_back(id);
		}
	}
	
	for(int i=0;i<n;i++){
		scanf("%s",name);
		string qs(name);
		printf("%s %d",name,stu[qs].size());
		if(stu[qs].size()>0){
			sort(stu[qs].begin(),stu[qs].end());
			for(int j=0;j<stu[qs].size();j++){
				printf(" %d",stu[qs][j]);
			}
		}
		printf("\n");
	}
	getchar();
	getchar();
	return 0;
}