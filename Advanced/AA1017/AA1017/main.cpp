#include<stdio.h>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> vcmp;
int findn(int n){
	if(vcmp.empty())
		return -1;
	int mid=(vcmp.size()-1)/2;
	int start=0,end=vcmp.size()-1;
	while(vcmp[mid]!=n&&mid>start){
			if(vcmp[mid]>n)
				end=mid;
			else if(vcmp[mid]<n)
				start=mid;
			
			mid=(end+start)/2;
	}
	if(vcmp[mid]!=n)
		return -1;

	return mid;
}
int findinsertn(int n){
	if(vcmp.empty())
		return -1;

	if(*(vcmp.end()-1)<=n)
		return vcmp.size();

	if(*vcmp.begin()>=n)
		return 0;

	int mid=(vcmp.size()-1)/2;
	int start=0,end=vcmp.size()-1;
	while(vcmp[mid]!=n&&mid>start){
		if(vcmp[mid]>n){
			end=mid;
			mid=(end+start)/2;
		}else if(vcmp[mid]<n){
			start=mid;
			mid=(end+start)/2;
		}
	}
	if(vcmp[mid]==n)
		return mid;

	return mid+1;
}
int findn(int n,int begin,int end){
	if(end-begin==0){
		return begin;
	}
	if(end-begin<0){
		return -1;
	}
	int mid=(end+begin)/2;
	if(vcmp[mid]>n)
		return findn(n,begin,mid-1);
	else if(vcmp[mid]<n)
		return findn(n,mid+1,end);
	else return mid;
}
void pushn(int n){
	int i=findinsertn(n);
	if(i==-1){
		vcmp.push_back(n);
		return;
	}
	vcmp.insert(vcmp.begin()+i,n);
}
void popn(int n){
	int i=findn(n);
	if(i==-1){
		return;
	}
	vcmp.erase(vcmp.begin()+i);
}

int main(){
	int n;
	scanf("%d",&n);
	stack<int> st;
	char com[50];
	for(int i=0;i<n;i++){
		scanf("%s",com);
		string s(com);
		if(s.find("Push")!=s.npos){
			int t;
			scanf("%d",&t);
			st.push(t);
			pushn(t);
		}else if(s.find("Pop")!=s.npos){
			if(!st.empty()){
				popn(st.top());
				printf("%d\n",st.top());
				st.pop();
			}else
				printf("Invalid\n");
		}else{
			if(!st.empty()){
				//sort(vcmp.begin(),vcmp.end());
				int mid;
				if(vcmp.size()%2==0) mid=vcmp.size()/2;
				else mid=(vcmp.size()+1)/2;
				printf("%d\n",vcmp[mid-1]);
			}else
				printf("Invalid\n");

		}
	}
	getchar();
	getchar();
	return 0;
}