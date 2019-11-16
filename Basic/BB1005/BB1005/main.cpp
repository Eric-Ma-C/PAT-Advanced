#include<stdio.h>
//#include<stdlib.h>
#include<algorithm>
#include<vector>
//35min
typedef struct Stu{
	int id;
	int de;
	int cai;
}Stu;

bool cmp(Stu s1,Stu s2){
	if(s1.de+s1.cai  <  s2.de+s2.cai)
		return false;
	if(s1.de+s1.cai  ==  s2.de+s2.cai
		&&s1.de  <  s2.de)
		return false;
	if(s1.de+s1.cai  ==  s2.de+s2.cai
		&&s1.de  ==  s2.de
		&&s1.id  >  s2.id)
		return false;

	return true;

}
int main(){
	int n,l,h;
	scanf("%d %d %d",&n,&l,&h);

	//Stu *list=(Stu*)malloc(sizeof(Stu)*n);
	Stu s;
	std::vector<Stu> v1,v2,v3,v4;
	int count=0;
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&s.id,&s.de,&s.cai);
		if(s.de<l||s.cai<l)
			continue;

		count++;
		if(s.cai>=h&&s.de>=h)
			v1.push_back(s);
		else if(s.de>=h&&s.cai<h)
			v2.push_back(s);
		else if(s.de>=s.cai)
			v3.push_back(s);
		else
			v4.push_back(s);
	}

	std::sort(v1.begin(),v1.end(),cmp);
	std::sort(v2.begin(),v2.end(),cmp);
	std::sort(v3.begin(),v3.end(),cmp);
	std::sort(v4.begin(),v4.end(),cmp);

	printf("%d\n",count);
	for(auto it=v1.begin();it!=v1.end();it++)
		printf("%08d %d %d\n",it->id,it->de,it->cai);
	for(auto it=v2.begin();it!=v2.end();it++)
		printf("%08d %d %d\n",it->id,it->de,it->cai);
	for(auto it=v3.begin();it!=v3.end();it++)
		printf("%08d %d %d\n",it->id,it->de,it->cai);
	for(auto it=v4.begin();it!=v4.end();it++)
		printf("%08d %d %d\n",it->id,it->de,it->cai);

getchar();
getchar();
return 0;
}