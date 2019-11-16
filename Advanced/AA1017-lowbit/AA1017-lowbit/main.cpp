#include<stdio.h>
#include<string>
#include<stack>
using namespace std;
//180min
#define MAX 100005
#define lowbit(i) ((i)&(-i))
stack<int> st;
int c[MAX]={0};//BIT
void update(int x,int v){
	for(int i=x;i<=MAX;i+=lowbit(i))
		c[i]+=v;
}
int getSum(int x){
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
		sum+=c[i];

	return sum;
}
int getMiddle(){//���ֲ��ҵ�һ��ʹgetSum(i)���ڵ�����λ����i
	int midcount=(st.size()+1)/2;
	int mid=MAX/2,start=1,end=MAX-1;//ע��BIT���±��1��ʼ
	int count;
	while(mid!=start){
		count=getSum(mid);
		if(count>=midcount)
			end=mid;
		else if(count<midcount)
			start=mid;
		mid=(start+end)/2;
	}
	if(mid==1&&getSum(1)>=midcount)//�������,ջ��ֻ��1�����ܶ��ٸ���
		return 1;

	return mid+1;
}
int main(){
	int n;
	scanf("%d",&n);
	char com[50];
	for(int i=0;i<n;i++){
		scanf("%s",com);
		string s(com);
		if(s.find("Push")!=s.npos){
			int t;
			scanf("%d",&t);
			st.push(t);
			update(t,1);//t��������һ
		}else if(s.find("Pop")!=s.npos){
			if(!st.empty()){
				update(st.top(),-1);//t��������һ
				printf("%d\n",st.top());
				st.pop();
			}else
				printf("Invalid\n");
		}else{
			if(!st.empty()){
				printf("%d\n",getMiddle());
			}else
				printf("Invalid\n");
		}
	}
	getchar();
	getchar();
	return 0;
}