#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);

	int q[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int outnum=0;
	char a[100][19];
	for(int i=0;i<n;i++){
		scanf("%s",a[i]);

		bool ok=true;
		for(int j=0;j<17;j++){
			if(a[i][j]<'0'||a[i][j]>'9'){
				ok=false;break;
			}
		}
		if(!ok){
			printf("%s\n",a[i]);
			outnum++;
			continue;
		}

		int sum=0;
		for(int j=0;j<17;j++){
			sum+=(a[i][j]-'0')*q[j];
		}
		int z=sum%11;char m=' ';
		switch(z){
		case 0:
			m='1';
			break;
			case 1:
			m='0';
			break;
			case 2:
			m='X';
			break;
			case 3:
			m='9';
			break;
			case 4:
			m='8';
			break;
			case 5:
			m='7';
			break;
			case 6:
			m='6';
			break;
			case 7:
			m='5';
			break;
			case 8:
			m='4';
			break;
			case 9:
			m='3';
			break;
			case 10:
			m='2';
			break;
		}

		if(a[i][17]!=m){
			printf("%s\n",a[i]);
			outnum++;
			continue;
		}
	}
	if(outnum==0)
		printf("All passed");

	getchar();
	getchar();
	return 0;
}