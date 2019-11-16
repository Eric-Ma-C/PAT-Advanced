//#include <iostream>
//using namespace std;
//int win[3] = {0};
//char max33(int *a) { 
//    char r = 'B';
//	if(a[1] > a[0]) { 
//	a[0] = a[1];
//	r = 'C';
//	}
//	if(a[2] > a[0]) r = 'J';
//	return r;
//}
//int main() {
//	int n;
//	char a[105],b[105];
//	int awin[3] = {0};
//	int bwin[3] = {0};
//	cin >> n;
//	for(int i = 0; i < n; i++) {
//		cin >> a[i] >> b[i];
//		int k = (a[i] - b[i]) * (a[i] - b[i]);
//		if(k == 1)
//			a[i] == 66 ? win[0]++,awin[0]++ : (win[1]++,bwin[0]++);
//		else if(k == 49)
//			a[i] == 67 ? win[0]++,awin[1]++ : (win[1]++,bwin[1]++);
//		else if(k == 64)
//			a[i] == 74 ? win[0]++,awin[2]++ : (win[1]++,bwin[2]++);
//		else
//			win[2]++;
//	}
//	cout << win[0] << " " << win[2] << " " << win[1] << endl;
//	cout << win[1] << " " << win[2] << " " << win[0] << endl;
//	cout << max33(awin) << " " << max33(bwin);
//	return 0;
//}


#include<stdio.h>

int max(int a,int b){
	if(a<b)
		return b;

	return a;
}
char getMost(int *n){
	int t=max(n[0],n[1]);
	t=max(t,n[2]);

	if(n[2]==t)
		return 'B';
	if(n[0]==t)
		return 'C';
	if(n[1]==t)
		return 'J';

	return 'B';
}
int main(){
	int num;
	int a[3]={0};//CJB
	int b[3]={0};
	int aa[3]={0};//spf
	scanf("%d",&num);

	char ta,tb;
	while(num>0){
		scanf("\n%c %c",&ta,&tb);
		if(ta=='C'){
			if(tb=='C'){
				aa[1]++;
			}else if(tb=='J'){
				aa[0]++;a[0]++;
			}else if(tb=='B'){
				aa[2]++;b[2]++;
			}
		}
		if(ta=='J'){
			if(tb=='C'){
				aa[2]++;b[0]++;
			}else if(tb=='J'){
				aa[1]++;
			}else if(tb=='B'){
				aa[0]++;a[1]++;
			}
		}
		if(ta=='B'){
			if(tb=='C'){
				aa[0]++;a[2]++;
			}else if(tb=='J'){
				aa[2]++;b[1]++;
			}else if(tb=='B'){
				aa[1]++;
			}
		}
		num--;
	}

	printf("%d %d %d\n%d %d %d\n",aa[0],aa[1],aa[2],aa[2],aa[1],aa[0]);
	char ia=getMost(a);
	char ib=getMost(b);
	printf("%c %c",ia,ib);

	getchar();
	getchar();
	return 0;
}