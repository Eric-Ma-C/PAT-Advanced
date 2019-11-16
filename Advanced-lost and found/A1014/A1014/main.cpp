#include<stdio.h>
#include<stdlib.h>
#include<vector>
//29min   float≈–0
typedef struct poly{
	int e;
	float a;
}poly;

int main(){
	int n1,n2;
	scanf("%d",&n1);
	poly* l1=(poly*)malloc(sizeof(poly)*n1);
	for(int i=0;i<n1;i++){
		scanf("%d %f",&l1[i].e,&l1[i].a);
	}
	scanf("%d",&n2);
	poly* l2=(poly*)malloc(sizeof(poly)*n2);
	for(int i=0;i<n2;i++){
		scanf("%d %f",&l2[i].e,&l2[i].a);
	}

	std::vector<poly> la;int i1=0,i2=0;
	for(;i1<n1&&i2<n2;){
		if(l1[i1].e>l2[i2].e)
		{la.push_back(l1[i1]);i1++;}
		else if(l1[i1].e<l2[i2].e)
		{la.push_back(l2[i2]);i2++;}
		else
		{poly p;p.e=l1[i1].e;p.a=l1[i1].a+l2[i2].a;
		if(p.a>0.001||p.a<-0.001)
			la.push_back(p);
		i1++;i2++;}
	}
	if(i1<n1)
		for(;i1<n1;i1++)
			la.push_back(l1[i1]);
	if(i2<n2)
		for(;i2<n2;i2++)
			la.push_back(l2[i2]);

	printf("%d ",la.size());
	auto it=la.begin();
	for(;it!=la.end()-1;it++){
		printf("%d %.1f ",it->e,it->a);
	}
	printf("%d %.1f",it->e,it->a);

	getchar();
	getchar();
	return 0;
}