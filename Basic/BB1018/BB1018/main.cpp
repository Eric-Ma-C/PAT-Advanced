#include<stdio.h>
#include<string.h>
typedef struct man{
	char name[6];
	int year;
	int month;
	int day;
};

bool isEarlier(man m1,man m2){
	if(m1.year>m2.year||
		(m1.year==m2.year&&m1.month>m2.month)||
		(m1.year==m2.year&&m1.month==m2.month&&m1.day>=m2.day)){
			return false;
		}

	return true;
}
bool isLater(man m1,man m2){
	if(m1.year<m2.year||
		(m1.year==m2.year&&m1.month<m2.month)||
		(m1.year==m2.year&&m1.month==m2.month&&m1.day<=m2.day)){
			return false;
		}

	return true;
}
int main(){
	man young,old,tmp;
	young.year=1814;young.month=9;young.day=6;
	old.year=2014;old.month=9;old.day=6;
	int num=0,count=0;
	man m0,m200;
	m0.year=2014;m0.month=9;m0.day=6;
	m200.year=1814;m200.month=9;m200.day=6;
	scanf("%d",&num);
	while(num-->0){
		scanf("%s %d/%d/%d",tmp.name,&tmp.year,&tmp.month,&tmp.day);
		if(isEarlier(tmp,m200)){
			continue;
		}else if(isLater(tmp,m0)){
			continue;
		}else{
			count++;
			if(isEarlier(tmp,old)){
				memcpy(&old,&tmp,sizeof(man));
			} 
			if(isLater(tmp,young)){
				memcpy(&young,&tmp,sizeof(man));
			}
		}
	}

	printf("%d %s %s",count,old.name,young.name);
	getchar();
	getchar();
	return 0;
}