#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll toNum(char t){
	if(t>='0'&&t<='9')
		return t-'0';
	if(t>='a'&&t<='z')
		return t-'a'+10;
	return 1;
}
ll getdec(string s,ll r){
	ll a=0;
	for(int i=0;i<s.size();i++){
		a+=toNum(s[i]);
		if(i!=s.size()-1)
			a*=r;
	}
	return a;
}
ll getr(string s,ll dec){
	string tmp=s;
	sort(tmp.begin(),tmp.end());
	ll r=toNum(tmp[tmp.size()-1])+1;
	if(r<2)r=2;
	ll min=r,max=1e10,t;
	ll mid=(min+max)/2;
	while(mid>min){
		t=getdec(s,mid);
		if(t>=dec||t<0){
			max=mid;
		}else{
			min=mid;
		}
		mid=(min+max)/2;
	}
	t=getdec(s,mid);
	if(t!=dec) {
		t=getdec(s,++mid);
		if(t!=dec) {
			return -1;
		}
	}
	return mid;
	//for(;r<=1e6;r++){
	//	t=getdec(s,r);
	//if(t==dec)
	//	return r;
	//if(t>dec)
	//	return -1;
	//}
	//return mid;
}
int main(){
	char n1[15],n2[15];ll tag,r;
	scanf("%s%s%lld%lld",n1,n2,&tag,&r);

	ll t=0,ans=-1;
	if(tag==1){
		t=getdec(string(n1),r);
		ans=getr(string(n2),t);
	}else {
		t=getdec(string(n2),r);
		ans=getr(string(n1),t);
	}
	if(ans==-1)
		printf("Impossible\n");
	else
		printf("%lld\n",ans);

	getchar();
	getchar();
	return 0;
}

