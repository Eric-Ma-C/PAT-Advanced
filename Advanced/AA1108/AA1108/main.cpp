#include<stdio.h>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
//32min
vector<double> leg;
double str2double(string s){
	double d;
	stringstream st(s);
	st>>d;
	return d;
}
int main(){
	int n;
	scanf("%d",&n);
	char c[1000];
	for(int i=0;i<n;i++){
		scanf("%s",c);
		
		string s(c);
		int dot=-1;bool ok=true;
		for(int i=0;i<s.size();i++){
			if((s[i]>'9'||s[i]<'0')){
				if(s[i]=='.'){
					if(dot>0||i==0){
						ok=false;
						break;
					}
					dot=i;
				}else if(i==0&&s[i]=='-'){
					continue;
				}else{
					ok=false;
					break;
				}
			}
		}
		if(dot>0&&s.size()-1-dot>2)
			ok=false;
		double d=str2double(s);
		if(d>1000||d<-1000)
			ok=false;

		if(ok){
			leg.push_back(d);
		}else{
			printf("ERROR: %s is not a legal number\n",s.c_str());
		}
	}
	double sum=0.0;
	for(int i=0;i<leg.size();i++){
		sum+=leg[i];
	}

	if(leg.size()==0)
		printf("The average of 0 numbers is Undefined");
	else if(leg.size()>1)
		printf("The average of %d numbers is %.2f",leg.size(),sum/leg.size());
	else 
		printf("The average of 1 number is %.2f",leg.size(),sum);


	getchar();
	getchar();
	return 0;
}