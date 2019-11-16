#include<stdio.h>
#include<algorithm>
//80min
int a[103]={0};
int a1[103]={0};
int t[103]={0};

bool issame(int *a,int* b,int n){
	bool same=true;
	while(n-->=0){
		if(a[n]!=b[n]){same=false;break;}
	}
	return same;
}

void merge2(int *a,int s,int e){
	std::sort(a+s,a+e+1);
}
int main(){
	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		a1[i]=a[i];
	}
	for(int i=0;i<n;i++){
		scanf("%d",t+i);
	}
	bool insert=false,merge=false;
	for(int i=1;i<n;i++){
		int j=i-1;int tmp=a[i];
		if(tmp>=a[j])
			continue;
		while(tmp<a[j]&&j>=0){
			a[j+1]=a[j];j--;}

		a[j+1]=tmp;

		if(insert){
			printf("Insertion Sort\n");
			for(int k=0;k<n-1;k++)
				printf("%d ",a[k]);

			printf("%d",a[n-1]);
			break;
		}
		if(issame(t,a,n))
		{insert=true;}
	}

	if(!insert){
		for(int step=2;step<=n;step*=2){
			for(int i=0;step*i<=n;i++){
				int end=i*step+step-1;
				end=end<n?end:n-1;
				merge2(a1,i*step,end);
			}

			if(merge){
				printf("Merge Sort\n");
				for(int k=0;k<n-1;k++)
					printf("%d ",a1[k]);

				printf("%d",a1[n-1]);
				break;
			}
			if(issame(t,a1,n))
			{merge=true;}
		}
	}


	getchar();
	getchar();
	return 0;
}