#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
//62min 题目不严谨
typedef struct stu{
	char id[20];
	int cg,mg,eg;float ag;
	int cr,mr,er,ar;

}stu;


bool cmpc(stu s1,stu s2){
	if(s1.cg>s2.cg)
		return true;
	return false;
}
bool cmpm(stu s1,stu s2){
	if(s1.mg>s2.mg)
		return true;
	return false;
}
bool cmpe(stu s1,stu s2){
	if(s1.eg>s2.eg)
		return true;
	return false;
}
bool cmpa(stu s1,stu s2){
	if(s1.ag>s2.ag)
		return true;
	return false;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);

	stu* s=(stu*)malloc(sizeof(stu)*n);
	for(int i=0;i<n;i++){
		scanf("%s %d %d %d",&s[i].id,&s[i].cg,&s[i].mg,&s[i].eg);
		s[i].ag=(s[i].cg+s[i].mg+s[i].eg)/3.0;
	}

	sort(s,s+n,cmpc);int ra=1;s[0].cr=ra;
	for(int i=1;i<n;i++){
		if(s[i].cg<s[i-1].cg)
			ra++;
		s[i].cr=ra;
	}
	sort(s,s+n,cmpm); ra=1;s[0].mr=ra;
	for(int i=1;i<n;i++){
		if(s[i].mg<s[i-1].mg)
			ra++;
		s[i].mr=ra;
	}
	sort(s,s+n,cmpe); ra=1;s[0].er=ra;
	for(int i=1;i<n;i++){
		if(s[i].eg<s[i-1].eg)
			ra++;
		s[i].er=ra;
	}
	sort(s,s+n,cmpa); ra=1;s[0].ar=ra;
	for(int i=1;i<n;i++){
		if(s[i].ag-s[i-1].ag<-1e-8)
			ra++;
		s[i].ar=ra;
	}

	char tmp[20];
	for(int i=0;i<m;i++){
		scanf("%s",&tmp);
		int j=0;
		for(;j<n;j++){
			if(strcmp(tmp,s[j].id)==0){
				if(s[j].ar<=s[j].cr&&s[j].ar<=s[j].mr&&s[j].ar<=s[j].er)
					printf("%d %c\n",s[j].ar,'A');
				else if(s[j].cr<=s[j].ar&&s[j].cr<=s[j].mr&&s[j].cr<=s[j].er)
					printf("%d %c\n",s[j].cr,'C');
				else if(s[j].mr<=s[j].cr&&s[j].mr<=s[j].ar&&s[j].mr<=s[j].er)
					printf("%d %c\n",s[j].mr,'M');
				else if(s[j].er<=s[j].cr&&s[j].er<=s[j].ar&&s[j].er<=s[j].mr)
					printf("%d %c\n",s[j].er,'E');

				break;
			}
		}
		if(j==n){printf("N/A\n");}

	}
	getchar();
	getchar();
	return 0;
}