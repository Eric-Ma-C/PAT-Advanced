#include<stdio.h>
#include<string.h>
//12min
int main(){
	int n;
	scanf("%d",&n);

	char early[17],late[17];

	int ehour=24,lhour=0,emin=60,lmin=0,esec=60,lsec=0;
	char tname[17];int th,tm,ts;
	for(int i=0;i<n;i++){
	scanf("%s %d:%d:%d",tname,&th,&tm,&ts);
	if(th<ehour||(th==ehour&&tm<emin)||(th==ehour&&tm==emin&&ts<esec)){
		strcpy(early,tname);
		ehour=th;emin=tm;esec=ts;
	}
	scanf("%d:%d:%d",&th,&tm,&ts);
	if(th>lhour||(th==lhour&&tm>lmin)||(th==lhour&&tm==lmin&&ts>lsec)){
		strcpy(late,tname);
		lhour=th;lmin=tm;lsec=ts;
	}


	}

	printf("%s %s",early,late);
	getchar();
	getchar();
	return 0;
}