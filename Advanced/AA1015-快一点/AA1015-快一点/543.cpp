#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//180min 之前超时
typedef struct stu{
	int id,ge,gi;
	int ch[5];
}stu;
int n,m,K;
int quota[105];
int lowestge[105];
int lowestgi[105];

priority_queue<int,vector<int>,greater<int> > result[105];//录取结果
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
	for(int i=0;i<m;i++)
		scanf("%d",quota+i);
	
	for(int i=0;i<n;i++){
		stu st;st.id=i;
		scanf("%d %d",&st.ge,&st.gi);
		for(int k=0;k<K;k++){
			scanf("%d",&st.ch[k]);
		}
		s.push_back(st);
	}
	sort(s.begin(),s.end(),cmp);
	fill(lowestge,lowestge+m,-1);
	fill(lowestgi,lowestgi+m,-1);

	for(int i=0;i<s.size();i++){
		for(int j=0;j<K;j++){
			int sch=s[i].ch[j];
			if(quota[sch]>0||
				(lowestgi[sch]==s[i].gi&&lowestge[sch]==s[i].ge)){
					result[sch].push(s[i].id);		
					lowestgi[sch]=s[i].gi;
					lowestge[sch]=s[i].ge;
					quota[sch]--;
					break;
			}
		}
	}

	for(int i=0;i<m;i++){
		if(result[i].size()==0){
			printf("\n");
			continue;
		}
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
////#include<queue>
//#include<algorithm>
//using namespace std;
////180min 之前超时
//typedef struct stu{
//	int id,ge,gi;
//	int ch[5];
//}stu;
//int n,m,K;
//int quota[105];
//int lowestge[105];
//int lowestgi[105];
//
//vector<int> result[105];//录取结果
//vector<stu> s;
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
//	for(int i=0;i<m;i++)
//		scanf("%d",quota+i);
//	
//	for(int i=0;i<n;i++){
//		stu st;st.id=i;
//		scanf("%d %d",&st.ge,&st.gi);
//		for(int k=0;k<K;k++){
//			scanf("%d",&st.ch[k]);
//		}
//		s.push_back(st);
//	}
//	sort(s.begin(),s.end(),cmp);
//	fill(lowestge,lowestge+m,-1);
//	fill(lowestgi,lowestgi+m,-1);
//
//	for(int i=0;i<s.size();i++){
//		for(int j=0;j<K;j++){
//			int sch=s[i].ch[j];
//			if(quota[sch]>0||
//				(lowestgi[sch]==s[i].gi&&lowestge[sch]==s[i].ge)){
//					result[sch].push_back(s[i].id);		
//					lowestgi[sch]=s[i].gi;
//					lowestge[sch]=s[i].ge;
//					quota[sch]--;
//					break;
//			}
//		}
//	}
//
//	for(int i=0;i<m;i++){
//		if(result[i].size()==0){
//			printf("\n");
//			continue;
//		}
//		sort(result[i].begin(),result[i].end());
//		printf("%d",result[i][0]);
//		for(int j=1;j<result[i].size();j++)
//			printf(" %d",result[i][j]);
//
//		printf("\n");
//
//	}
//
//	getchar();
//	getchar();
//	return 0;
//}
