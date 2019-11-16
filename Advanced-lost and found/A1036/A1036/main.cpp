#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
//41min
typedef struct Stu{
	long long id;
	int grade,place,rank,rankLocal;
}Stu;
bool cmp(Stu s1,Stu s2){
	if(s1.grade!=s2.grade)
		return s1.grade>s2.grade;
	else{
		return s1.id<s2.id;
	}
}
int main(){
	int n,k;
	scanf("%d",&n);
	vector<Stu> all;
	for(int i=0;i<n;i++){
		int p;
		scanf("%d",&p);
		vector<Stu> sp;
		Stu t;
		for(int j=0;j<p;j++){
			scanf("%lld %d",&t.id,&t.grade);
			t.place=i+1;
			sp.push_back(t);
		}
		sort(sp.begin(),sp.end(),cmp);
		int r=1;sp[0].rankLocal=1;
		for(int j=1;j<p;j++){
			if(sp[j].grade!=sp[j-1].grade)
				r=j+1;
			sp[j].rankLocal=r;
		}
		all.insert(all.begin(),sp.begin(),sp.end());
	}
	sort(all.begin(),all.end(),cmp);
	int r=1;all[0].rank=1;
	int size=all.size();
	for(int j=1;j<size;j++){
		if(all[j].grade!=all[j-1].grade)
			r=j+1;
		all[j].rank=r;
	}
	printf("%d\n",size);
	for(int j=0;j<size;j++){
		printf("%013lld %d %d %d\n",all[j].id,all[j].rank,all[j].place,all[j].rankLocal);
	}

	getchar();
	getchar();
	return 0;
}