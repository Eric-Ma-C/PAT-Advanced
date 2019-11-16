#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> ans;
vector<int> tmp;
int N,K,P;	
int summax=0;//��ǰ����
bool newans(){
	int sum=0;
	for(int i=0;i<K;i++){
		sum+=tmp[i];
	}
	if(sum>summax){//�и���ĺ�
		summax=sum;
		return true;
	}else if(sum==summax){//����ȣ��и�������
		for(int i=0;i<K;i++){
			if(tmp[i]!=ans[i])
				return tmp[i]>ans[i];
		}
	}else{
		return false;
	}
}
void kpn(int k,int n){
	if(k==1){
		int t=pow(n,1.0/P);
		if((int)pow(t*1.0,P)==n){
			tmp.push_back(t);
			if(newans()){//���½��
				ans.insert(ans.begin(),tmp.begin(),tmp.end());
			}
			tmp.pop_back();
		}
		return;
	}
	int min=pow(n*1.0/k,1.0/P);
	int t=pow(min*1.0,P)*k;
	if(t<n)
		min++;
	int max=pow((n-k+1)*1.0,1.0/P);
	if(tmp.size()!=0&&max>tmp.back())//��֤�������������ǰ�����
		max=tmp.back();
	for(int i=min;i<=max;i++){//��kλ��С������
		tmp.push_back(i);
		int nn=n-pow(i*1.0,P);
		kpn(k-1,nn);
		tmp.pop_back();
	}
}
int main(){
	scanf("%d%d%d",&N,&K,&P);
	kpn(K,N);

	if(ans.size()==0){
		printf("Impossible\n");
		return 0;
	}
	printf("%d = ",N);
	for(int i=0;i<K;i++){
		if(i!=0)printf(" + ");
		printf("%d^%d",ans[i],P);
	}
	getchar();
	getchar();
	return 0;
}
//390 21 2