#include<stdio.h>
#include<string.h>

int main(){
	char c1[70],c2[70],c3[70],c4[70];
	scanf("%s%s%s%s",c1,c2,c3,c4);

	char day=0,hour=0,min=0;
	for(int i=0;i<strlen(c1)&&i<strlen(c2);i++){
		if(c1[i]==c2[i]&&((c1[i]>='A'&&c1[i]<='N')||(c1[i]>='0'&&c1[i]<='9'))){
			if(day!=0&&hour==0)
				hour=c1[i];
		}
		if(c1[i]==c2[i]&&c1[i]>='A'&&c1[i]<='G'){
			if(day==0)
				day=c1[i];
		}

	}
	for(int i=0;i<strlen(c3)&&i<strlen(c4);i++){
		if(c3[i]==c4[i]&&((c3[i]>='A'&&c3[i]<='Z')||(c3[i]>='a'&&c3[i]<='z'))){
			if(min==0)
			{min=i;break;}
		}
	}
	switch(day){

	case 'A':
		printf("MON ");
		break;
	case 'B':
		printf("TUE ");
		break;
	case 'C':
		printf("WED ");
		break;
	case 'D':
		printf("THU ");
		break;
	case 'E':
		printf("FRI ");
		break;
	case 'F':
		printf("SAT ");
		break;
	case 'G':
		printf("SUN ");
		break;
	}
	if(hour>='0'&&hour<='9')
		printf("%02d:",hour-'0');
	else 
		printf("%02d:",hour-'A'+10);

	printf("%02d",min);

	getchar();
	getchar();
	return 0;
}