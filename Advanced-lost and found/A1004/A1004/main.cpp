#include<stdio.h>
#include<string.h>
#include<stack>

//57min  pat's test data has unique node number(1-n), but niuke is not!!! 
int pre[31];
int in[31];
int data[31];//key-value
int n;int num=0;
void postTravel(int p1,int p2,int i1,int i2){
	if(p2-p1<0)
		return;
	if(p2-p1==0){
		printf("%d",data[pre[p1]]);
		num++;
	}else if(p2-p1==1){
		printf("%d ",data[pre[p2]]);
		printf("%d",data[pre[p1]]);
		num++;num++;
	}else if(p2-p1>=2){
		int root=pre[p1];
		int i=i1;
		for(;i<=i2&&i<n;i++)
		{if(in[i]==root)
			break;
		}

		postTravel(p1+1,p1+1+(i-1-i1),i1,i-1);//left
		postTravel(p1+1+(i-1-i1)+1,p2,i+1,i2);//right

		printf("%d",data[root]);
		num++;
	}
	
	if(num!=n)
		printf(" ");
}
int main(){
	
	scanf("%d",&n);
	int put=0,popt=0;
	std::stack<int> st;
	char s[30]={0};
	for(int i=0;i<2*n;i++){
		scanf("%s",s);
		if(strcmp(s,"Push")==0){
			int t=0;
			scanf("%d",&t);
			st.push(put);pre[put]=put;data[put]=t;put++;
		}else{
			in[popt++]=st.top();
			st.pop();
		}
	}

	postTravel(0,n-1,0,n-1);

	getchar();
	getchar();
	return 0;
}