#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

typedef struct dtime{
	int hour,min,sec;
}dtime;
typedef struct record{
	char num[8];
	dtime t;
	bool in;
}record;
typedef struct car{
	char num[8];
	int insec,outsec,parksec;
	//friend bool operator < (car c1,car c2){return c1.parksec<c2.parksec;}
}car;
int n,k;
vector<record> rl;
vector<dtime> ql;
vector<car> cars;
map<string,int> park;

int getsec(dtime t){
	return 3600*t.hour+60*t.min+t.sec;
}
bool cmp(record r1,record r2){
	return getsec(r1.t)<getsec(r2.t);
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		record r;char ct[5];
		scanf("%s %d:%d:%d %s",r.num,&r.t.hour,&r.t.min,&r.t.sec,ct);
		r.in=ct[0]=='i'?true:false;
		rl.push_back(r);
	}
	for(int i=0;i<k;i++){
		dtime t;
		scanf("%d:%d:%d",&t.hour,&t.min,&t.sec);
		ql.push_back(t);
	}
	sort(rl.begin(),rl.end(),cmp);
	for(int i=0;i<rl.size();i++){
		if(rl[i].in){

			for(int j=i+1;j<rl.size();j++){
				if(strcmp(rl[i].num,rl[j].num)==0){
					if(rl[j].in)
						break;
					else {
						car c;strcpy(c.num,rl[i].num);
						c.insec=getsec(rl[i].t);
						c.outsec=getsec(rl[j].t);
						c.parksec=c.outsec-c.insec;
						cars.push_back(c);

						//rl.erase(rl.begin()+i);
						rl.erase(rl.begin()+j);
						//i-=1;
						break;
					}
				}//if

			}//for
		}//if
	}

	int count[3600*24]={0};

	for(int i=0;i<cars.size();i++){
		for(int j=cars[i].insec;j<cars[i].outsec;j++)
			count[j]++;
	}


	for(int i=0;i<ql.size();i++){
		int t=getsec(ql[i]);

		/*int count=0;
		for(int j=0;j<cars.size();j++){
		if(cars[j].insec<=t&&cars[j].outsec>t)
		count++;
		}*/
		printf("%d\n",count[t]);
	}
	vector<string> c;
	int max=0;
	for(int j=0;j<cars.size();j++){
		string str(cars[j].num);
		if(park.find(str)==park.end())
			park[str]=cars[j].parksec;
		else
			park[str]+=cars[j].parksec;
	}

	for(auto it=park.begin();it!=park.end();it++){
		if(it->second>=max){
			if(it->second>max)
				c.clear();
			c.push_back(it->first);
			max=it->second;
		}
	}
	for(int i=0;i<c.size();i++){
		printf("%s ",c[i].c_str());
	}
	int sec=max;
	int h=sec/3600;sec=sec%3600;
	int m=sec/60;int s=sec%60;
	printf("%02d:%02d:%02d",h,m,s);
	getchar(); 
	getchar();
	return 0;
}