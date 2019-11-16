#include<stdio.h>
#include<algorithm>
//24min
typedef struct Stu{
	char name[11];
	char ID[11];
	int grade;

	//friend bool operator>
}Stu;
bool cmp(Stu s1,Stu s2){
	if(s1.grade>s2.grade)
		return true;

	return false;
}
int main(){
	int n;
	scanf("%d",&n);

	Stu* list=(Stu*)malloc(sizeof(Stu)*n);
	for(int i=0;i<n;i++){
		scanf("%s %s %d",&list[i].name,&list[i].ID,&list[i].grade);
	}

	std::sort(list,list+n,cmp);
	int low,high;
	scanf("%d %d",&low,&high);

	int num=0;
	for(int i=0;i<n;i++){
		if(list[i].grade>=low&&list[i].grade<=high){
			printf("%s %s\n",list[i].name,list[i].ID);num++;
		}
	}
	if(num==0)
		printf("NONE");

getchar();
getchar();
return 0;
}