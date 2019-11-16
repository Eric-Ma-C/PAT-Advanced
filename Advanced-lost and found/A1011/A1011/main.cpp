#include<stdio.h>
#include<stdlib.h>
//15min
typedef struct Stu{
	char name[11];
	char sex;
	char id[11];
	int grade;
}Stu;
int main(){
	int n;
	scanf("%d",&n);
	int max=0,min=101,f=-1,m=-1;
	Stu* list=(Stu*)malloc(sizeof(Stu)*n);
	for(int i=0;i<n;i++){
		scanf("%s %c %s %d",&list[i].name,&list[i].sex,&list[i].id,&list[i].grade);
		if(list[i].sex=='F'&&list[i].grade>max)
		{max=list[i].grade;f=i;}
		if(list[i].sex=='M'&&list[i].grade<min)
		{min=list[i].grade;m=i;}
	}
	int sub=9999;
	if(f!=-1)
		printf("%s %s\n",list[f].name,list[f].id);
	else
		printf("Absent\n");
	if(m!=-1)
		printf("%s %s\n",list[m].name,list[m].id);
	else
		printf("Absent\n");

	if(f!=-1&&m!=-1)
		printf("%d",list[f].grade-list[m].grade);
	else
		printf("NA");

	getchar();
	getchar();
	return 0;
}