#include<stdio.h>
int t[1005];
int ans[1005];
int n;
bool ispre(int b,int e){
	if(b>e||e>n-1)return true;
	if(b==e){
		return true;
	}
	int r=t[b];
	int f=b+1;
	while(f<=e&&t[f]<r)
		f++;
	for(int i=f;i<=e;i++){
		if(t[i]<r)
			return false;
	}
	bool isp1=ispre(b+1,f-1);
	bool isp2=ispre(f,e);
	return isp1&&isp2;
}
bool ispre2(int b,int e){
	if(b>e||e>n-1)return true;
	if(b==e){
		return true;
	}

	int r=t[b];
	int f=b+1;
	while(f<=e&&t[f]>=r)
		f++;
	for(int i=f;i<=e;i++){
		if(t[i]>=r)
			return false;
	}
	bool isp1=ispre2(b+1,f-1);
	bool isp2=ispre2(f,e);
	return isp1&&isp2;
}
void getpost(int b,int e,int bp,int ep){
	if(b>e||e>n-1)return ;
	if(b==e){
		ans[bp]=t[b];
		return ;
	}
	int r=t[b];
	ans[ep]=r;
	int f=b+1;
	while(f<=e&&t[f]<r)
		f++;
	getpost(b+1,f-1,bp,bp+f-b-2);
	getpost(f,e,bp+f-b-1,ep-1);
	return;
}
void getpost2(int b,int e,int bp,int ep){
	if(b>e||e>n-1)return ;
	if(b==e){
		ans[bp]=t[b];
		return ;
	}
	int r=t[b];
	ans[ep]=r;
	int f=b+1;
	while(f<=e&&t[f]>=r)
		f++;
	getpost2(b+1,f-1,bp,bp+f-b-2);
	getpost2(f,e,bp+f-b-1,ep-1);
	return;
}
int main(){

	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%d",t+i);
	}
	bool isp=ispre(0,n-1);
	if(!isp){
		isp=ispre2(0,n-1);
		if(isp){
			getpost2(0,n-1,0,n-1);
		}
	}else{
		getpost(0,n-1,0,n-1);
	}
	if(isp){
		printf("YES\n");
		for(int i=0;i<n;i++){
			printf("%d",ans[i]);
			if(i!=n-1)printf(" ");
		}
	}else printf("NO");

	getchar();
	getchar();
	return 0;
}