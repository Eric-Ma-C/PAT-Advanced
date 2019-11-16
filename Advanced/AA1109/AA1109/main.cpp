#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

typedef struct stu{
	string name;
	int h;
}stu;
vector<stu> l;

bool cmp(stu &s1,stu &s2){
	if(s1.h!=s2.h)
		return s1.h<s2.h;

	return s1.name>s2.name;
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int h;char cn[15];
	for(int i=0;i<n;i++){
		scanf("%s %d",cn,&h);
		string sn(cn);
		stu s;
		s.h=h;
		s.name=sn;
		l.push_back(s);
	}
	sort(l.begin(),l.end(),cmp);
	int rnum=floor(n*1.0/k+0.5);

	vector<vector<stu> > form;
	for(int i=0;i<k-1;i++){
		vector<stu> tl;

		if(rnum%2==1){
			for(int j=i*rnum+1;j<(i+1)*rnum;j+=2)
				tl.push_back(l[j]);
			for(int j=(i+1)*rnum-1;j>=i*rnum;j-=2)
				tl.push_back(l[j]);
		}else{
			for(int j=i*rnum;j<(i+1)*rnum;j+=2)
				tl.push_back(l[j]);
			for(int j=(i+1)*rnum-1;j>=i*rnum;j-=2)
				tl.push_back(l[j]);
		}

		/*for(int j=(i+1)*rnum-1,count=0;j>=i*rnum;j--,count++){
		if(count%2==0){
		tl.push_back(l[j]);
		}else{
		tl.insert(tl.begin(),l[j]);			
		}
		}*/
		form.push_back(tl);
	}
	vector<stu> tl;
	int lrnum=n-(k-1)*rnum;
	if(lrnum%2==1){
		for(int j=(k-1)*rnum+1;j<n;j+=2)
			tl.push_back(l[j]);
		for(int j=n-1;j>=(k-1)*rnum;j-=2)
			tl.push_back(l[j]);
	}else{
		for(int j=(k-1)*rnum;j<n;j+=2)
			tl.push_back(l[j]);
		for(int j=n-1;j>=(k-1)*rnum;j-=2)
			tl.push_back(l[j]);
	}
	/*for(int j=n-1,count=0;j>=(k-1)*rnum;j--,count++){
	if(count%2==0){
	tl.push_back(l[j]);
	}else{
	tl.insert(tl.begin(),l[j]);			
	}
	}*/
	form.push_back(tl);

	for(int i=form.size()-1;i>=0;i--){
		for(int j=0;j<form[i].size();j++){
			if(j!=0)printf(" ");
			printf("%s",form[i][j].name.c_str());
		}
		printf("\n");
	}


	getchar();
	getchar();
	return 0;
}