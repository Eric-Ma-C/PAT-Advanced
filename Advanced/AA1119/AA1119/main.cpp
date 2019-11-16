#include<stdio.h>

int pre[35];//前序
int post[35];//后序
int in[35];//中序
bool unique=true;
void build(int b1,int e1,int b2,int e2,int inbegin){//b1,e1为pre[]起始下标 b2,e2为post[]起始下标,inbegin为in[]起点
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

	in[inbegin+lnum]=root;//根入位
	build(b1+1,b1+1+lnum-1,b2,b2+lnum-1,inbegin);//左子树
	build(b1+lnum+1,e1,b2+lnum,e2-1,inbegin+lnum+1);//右子树
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
	printf("\n");//少了换行符会格式错误，晕
	
	getchar();
	getchar();
	return 0;
}