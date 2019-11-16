#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
//180min
typedef struct Record{
	char name[25];
	int day,hour,min;
	bool online;
}Record;
int month;
int rate[24]={0};
bool cmp(Record r1,Record r2){
	if(strcmp(r1.name,r2.name)!=0)
		return strcmp(r1.name,r2.name)<0;
	else{
		if(r1.day!=r2.day)
			return r1.day<r2.day;
		else{
			if(r1.hour!=r2.hour)
				return r1.hour<r2.hour;
			else{
				return r1.min<r2.min;
			}
		}
	}
}
int getFee(Record r1,Record r2,int *minutes){
	int fee=0;
	int day=r2.day-r1.day;
	int hour=r2.hour-r1.hour;
	int min=r2.min-r1.min;
	*minutes=day*60*24+hour*60+min;
	int h=r1.hour,m60=60-r1.min;
	for(int i=0;i<*minutes;i++){
		m60--;
		fee+=rate[h];
		if(m60==0){//one hour pass
			m60=60;
			h++;h=h%24;
		}
	}
	return fee;
}
int main(){
	int n;
	for(int i=0;i<24;i++)
		scanf("%d",rate+i);

	scanf("%d",&n);
	Record* list=(Record*)malloc(sizeof(Record)*n);
	char tag[10];
	for(int i=0;i<n;i++){
		scanf("%s %d:%d:%d:%d %s",&list[i].name,&month,&list[i].day,&list[i].hour,&list[i].min,&tag);
		if(tag[1]=='n')
			list[i].online=true;
		else
			list[i].online=false;
	}

	sort(list,list+n,cmp);

	int cents=0;char tname[25]={0};
	bool isNewP=0;bool lastIsOn=false;
	for(int i=0;i<n;i++){
		if(strcmp(tname,list[i].name)!=0){//new preson
			if(cents!=0)
				printf("Total amount: $%.2f\n",cents/100.0);
			strcpy(tname,list[i].name);
			cents=0;isNewP=true;
			lastIsOn=list[i].online;
			continue;
		}

		if(lastIsOn&&list[i].online==false){//match
			if(isNewP){
				printf("%s %02d\n",tname,month);
				isNewP=false;
			}
			int mins;
			int cent=getFee(list[i-1],list[i],&mins);
			cents+=cent;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
				list[i-1].day,list[i-1].hour,list[i-1].min,
				list[i].day,list[i].hour,list[i].min,mins,cent/100.0);
		}
		lastIsOn=list[i].online;//漏了这句多花1 hour -_-
	}
	if(cents!=0)
		printf("Total amount: $%.2f\n",cents/100.0);
	getchar();
	getchar();
	return 0;
}