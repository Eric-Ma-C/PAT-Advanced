#include<stdio.h>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct clu{
	int num;
	set<int> hobby;
}clu;

vector<clu> h;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> th;
	for(int i=0;i<n;i++){
		int t,tmp;
		scanf("%d:",&t);

		th.clear();
		for(int j=0;j<t;j++){
			scanf("%d",&tmp);
			th.push_back(tmp);
		}
		int in=0;
		vector<int> c;//属于的圈子，大于一要合并
		for(;in<th.size();in++){
			for(int j=0;j<h.size();j++){
				if(h[j].hobby.find(th[in])!=h[j].hobby.end()){
					c.push_back(j);
					break;
				}
			}
		}
		if(c.size()==0){//new
			clu ct;ct.num=1;
			set<int> hob;
			for(int k=0;k<th.size();k++)
				hob.insert(th[k]);
			ct.hobby=hob;
			h.push_back(ct);
		}else{
			sort(c.begin(),c.end());
			if(c.size()>1){//合并
				for(int j=1;j<c.size();j++){
					for(auto it=h[c[j]].hobby.begin();it!=h[c[j]].hobby.end();it++){
						h[c[0]].hobby.insert(*it);
					}
					h[c[0]].num+=h[c[j]].num;
				}
				for(int j=c.size()-1;j>0;j--){	
					h.erase(h.begin()+c[j]);
				}
			}
			for(int k=0;k<th.size();k++)
				h[c[0]].hobby.insert(th[k]);

			h[c[0]].num++;
		}
	}
	vector<int> num;
	for(int i=0;i<h.size();i++)
		num.push_back(h[i].num);

	sort(num.begin(),num.end());
	printf("%d\n",h.size());
	for(int i=num.size()-1;i>=0;i--){
		if(i!=num.size()-1)printf(" ");
		printf("%d",num[i]);
	}

	getchar();
	getchar();
	return 0;
}

//8
//3: 2 7 10
//1: 4
//2: 5 3
//1: 4
//1: 3
//1: 4
//5: 6 8 1 5 4
//1: 4