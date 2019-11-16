#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
//18min
typedef struct st{
	int id;
	char name[9];
	int grade;
}st;
bool cmp1(st s1,st s2){
	if(s1.id<s2.id)
		return true;

	return false;
}
bool cmp2(st s1,st s2){
	if(strcmp(s1.name,s2.name)<0)
		return true;

	if(strcmp(s1.name,s2.name)==0)
		if(s1.id<s2.id)
			return true;

	return false;
}
bool cmp3(st s1,st s2){
	if(s1.grade<s2.grade)
		return true;

	if(s1.grade==s2.grade)
		if(s1.id<s2.id)
			return true;

	return false;
}
int main(){
	int n,c;
	scanf("%d %d",&n,&c);

	st* list=(st*)malloc(sizeof(st)*n);
	for(int i=0;i<n;i++){scanf("%d %s %d",&list[i].id,&list[i].name,&list[i].grade);}

	if(c==1)
		std::sort(list,list+n,cmp1);
	if(c==2)
		std::sort(list,list+n,cmp2);
	if(c==3)
		std::sort(list,list+n,cmp3);

	for(int i=0;i<n;i++){
		printf("%06d %s %d\n",list[i].id,list[i].name,list[i].grade);
	}
getchar();
getchar();
return 0;
}