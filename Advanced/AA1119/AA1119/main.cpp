#include<stdio.h>

int pre[35];//ǰ��
int post[35];//����
int in[35];//����
bool unique=true;
void build(int b1,int e1,int b2,int e2,int inbegin){//b1,e1Ϊpre[]��ʼ�±� b2,e2Ϊpost[]��ʼ�±�,inbeginΪin[]���
	if(b1>e1)
		return;
	if(b1==e1){
		in[inbegin]=pre[b1];
		return;
	}
	int root=pre[b1];
	int chnum=e1-b1;

	int maylch=pre[b1+1];
	int i=e2-1;
	for(;i>=b2&&post[i]!=maylch;i--)
		;
	int lnum=0;
	for(int j=i;j>=b2;j--,lnum++)
		;
	if(lnum==chnum)
		unique=false;

	in[inbegin+lnum]=root;//����λ
	build(b1+1,b1+1+lnum-1,b2,b2+lnum-1,inbegin);//������
	build(b1+lnum+1,e1,b2+lnum,e2-1,inbegin+lnum+1);//������
}
int main(){
	int n;
	scanf("%d",&n);
	int t;
	for(int i=0;i<n;i++){
		scanf("%d",pre+i);
	}
	for(int i=0;i<n;i++){
		scanf("%d",post+i);
	}
	build(0,n-1,0,n-1,0);

	if(unique){
		printf("Yes\n");
	}else{printf("No\n");}

	for(int i=0;i<n;i++){
		if(i!=0)printf(" ");
		printf("%d",in[i]);
	}
	printf("\n");//���˻��з����ʽ������
	
	getchar();
	getchar();
	return 0;
}