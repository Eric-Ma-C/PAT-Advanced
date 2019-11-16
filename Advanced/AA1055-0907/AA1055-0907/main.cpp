#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n,k;

typedef struct item{
	string name;
	int age,money;
	item(string n,int age,int money){this->name=n;this->age=age;this->money=money;}
	friend bool operator<(item i1,item i2){
		if(i1.money!=i2.money)
			return i1.money>i2.money;
		else{
			if(i1.age!=i2.age)
				return i1.age<i2.age;
			else{
				return i1.name<i2.name;
			}
		}
	}
}item;
vector<item> l;

bool cmp(item i1,item i2){
	return i1.age<i2.age;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		char na[10];int age,money;
		scanf("%s %d %d",na,&age,&money);
		l.push_back(item(string(na),age,money));
	}

	sort(l.begin(),l.end());
	for(int i=0;i<k;i++){
		int m,min,max;
		scanf("%d%d%d",&m,&min,&max);
		vector<item> tmp;
		int j=0;
		for(;j<l.size()&&tmp.size()<m;j++){
			if(l[j].age>=min&&l[j].age<=max)
				tmp.push_back(l[j]);
		}
		printf("Case #%d:\n",i+1);
		for(int j=0;j<tmp.size();j++){
			printf("%s %d %d\n",tmp[j].name.c_str(),tmp[j].age,tmp[j].money);
		}
		if(tmp.size()==0)
			printf("None\n");
	}

	getchar();
	getchar();
	return 0;
}

