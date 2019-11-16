#include<stdio.h>
//29min
int main(){
	char s1[61],s2[61],s3[61],s4[61];
	scanf("%s",s1);
	scanf("%s",s2);
	scanf("%s",s3);
	scanf("%s",s4);

	char day=0,hour=0;
	for(int i=0;s1[i]!='\0'&&s2[i]!='\0';i++){
		if(day&&!hour&&s1[i]==s2[i]&&((s1[i]>='A'&&s1[i]<='Z')||(s1[i]>='0'&&s1[i]<='9')))
			hour=s1[i];

		if(!day&&s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='Z')
			day=s1[i];
		
		if(day&&hour)
			break;
	}
	int min=0;
	for(int i=0;s3[i]!='\0'&&s4[i]!='\0';i++){
		if(s3[i]==s4[i]&&((s3[i]>='A'&&s3[i]<='Z')||(s3[i]>='a'&&s3[i]<='z')))
		{	min=i;
			break;
		}
	}
	
	switch(day-'A'+1){
	case 1:
		printf("MON ");
		break;
		case 2:
		printf("TUE ");
		break;
		case 3:
		printf("WED ");
		break;
		case 4:
		printf("THU ");
		break;
		case 5:
		printf("FRI ");
		break;
		case 6:
		printf("SAT ");
		break;
		case 7:
		printf("SUN ");
		break;
	}
	if(hour>='0'&&hour<='9')
		printf("%02d",hour-'0');
	else{
		printf("%02d",hour-'A'+10);
	}
	printf(":%02d",min);

	getchar();
	getchar();
	return 0;
}