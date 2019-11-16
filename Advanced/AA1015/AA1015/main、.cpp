#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct stu{
	int id,ge,gi;//,rank;
	int ch[5];
}stu;
int n,m,K;
int quota[100];
int remain[100];

priority_queue<int,vector<int>,greater<int> > result[100];//录取结果
vector<stu> s;
bool cmp(stu s1,stu s2){
	if((s1.ge+s1.gi)!=(s2.ge+s2.gi))
		return (s1.ge+s1.gi)>(s2.ge+s2.gi);
	else{
		if(s1.ge!=s2.ge)
			return s1.ge>s2.ge;
		else return false;
	}
}
int main(){
	scanf("%d %d %d",&n,&m,&K);
	for(int i=0;i<m;i++){
		scanf("%d",quota+i);
		remain[i]=quota[i];
	}
	for(int i=0;i<n;i++){
		stu st;st.id=i;
		scanf("%d %d",&st.ge,&st.gi);
		for(int k=0;k<K;k++){
			scanf("%d",&st.ch[k]);
		}
		s.push_back(st);
	}
	sort(s.begin(),s.end(),cmp);
	int samerank;
	for(int i=0;i<s.size();i++){
		stu st=s[i];
		vector<stu> prep;
		for(samerank=0;i+samerank<s.size()&&s[i+samerank].ge==st.ge
			&&s[i+samerank].gi==st.gi;samerank++)
			prep.push_back(s[i+samerank]);

		for(int k=0;k<K;k++){
			for(int j=0;j<prep.size();j++){//每个学生
				if(remain[prep[j].ch[k]]>0){
					result[prep[j].ch[k]].push(prep[j].id);
					prep.erase(prep.begin()+j);
					j--;
				}
			}
			for(int t=0;t<samerank;t++){
				int school=s[i+t].ch[k]; 
				remain[school]=quota[school]-result[school].size();
			}
		}
		i+=(samerank-1);
	}

	for(int i=0;i<m;i++){
		if(result[i].size()==0){
			printf("\n");
			continue;
		}
		//sort(result[i].begin(),result[i].end());
		printf("%d",result[i].top());result[i].pop();
		for(;!result[i].empty();result[i].pop())
			printf(" %d",result[i].top());

		printf("\n");

	}

	getchar();
	getchar();
	return 0;
}
//#include<stdio.h>
//#include<vector>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//typedef struct stu{
//	int id,ge,gi;//,rank;
//	int ch[5];
//}stu;
//int n,m,K;
//int quota[100];
//int remain[100];
//
//priority_queue<int,vector<int>,greater<int> > result[100];//录取结果
//stu s[40000];
//bool cmp(stu s1,stu s2){
//	if((s1.ge+s1.gi)!=(s2.ge+s2.gi))
//		return (s1.ge+s1.gi)>(s2.ge+s2.gi);
//	else{
//		if(s1.ge!=s2.ge)
//			return s1.ge>s2.ge;
//		else return false;
//	}
//}
//int main(){
//	scanf("%d %d %d",&n,&m,&K);
//	for(int i=0;i<m;i++){
//		scanf("%d",quota+i);
//		remain[i]=quota[i];
//	}
//	for(int i=0;i<n;i++){
//		s[i].id=i;
//		scanf("%d %d",&s[i].ge,&s[i].gi);
//		for(int k=0;k<K;k++){
//			scanf("%d",&s[i].ch[k]);
//		}
//	}
//	sort(s,s+n,cmp);
//	int samerank;
//	for(int i=0;i<n;i++){
//		stu st=s[i];
//		vector<stu> prep;
//		for(samerank=0;i+samerank<n&&s[i+samerank].ge==s[i].ge
//			&&s[i+samerank].gi==s[i].gi;samerank++)
//			prep.push_back(s[i+samerank]);
//
//		for(int k=0;k<K;k++){
//			for(int j=0;j<prep.size();j++){//每个学生
//				if(remain[prep[j].ch[k]]>0){
//					result[prep[j].ch[k]].push(prep[j].id);
//					prep.erase(prep.begin()+j);
//					j--;
//				}
//			}
//			for(int t=0;t<m;t++){
//				remain[t]=quota[t]-result[t].size();
//			}
//		}
//		i+=(samerank-1);
//	}
//
//	for(int i=0;i<m;i++){
//		if(result[i].size()==0){
//			printf("\n");
//			continue;
//		}
//		sort(result[i].begin(),result[i].end());
//		printf("%d",result[i].top());result[i].pop();
//		for(;!result[i].empty();result[i].pop())
//			printf(" %d",result[i].top());
//
//		printf("\n");
//
//	}
//
//	getchar();
//	getchar();
//	return 0;
//}