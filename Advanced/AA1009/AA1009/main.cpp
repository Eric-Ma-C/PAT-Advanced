#include<stdio.h>
//80min
int n,a[100],t[100],b[100];
bool issame(){
	for(int i=0;i<n;i++)
		if(t[i]!=b[i])
			return false;
	return true;
}
bool insert(){
	bool same=false;
	for(int i=1;i<n;i++){
		int j=i-1,it=t[i];
		while(t[j]>it&&j>=0){
			t[j+1]=t[j];
			j--;
		}
		t[j+1]=it;
		if(same)
			return true;
		same=issame();
	}
	return false;
}
void adjust(int v,int size){
	int tmp=t[v];
	while(v<=size/2-1){
		int l=v*2+1,r=v*2+2,bigc;
		if(l<size)
			bigc=l;
		else break;

		if(r<size&&t[r]>t[l])
			bigc=r;
		if(t[bigc]>tmp){
			t[v]=t[bigc];v=bigc;
		}else break;
	}
	t[v]=tmp;
}
void buildHeap(){
	for(int i=n/2-1;i>=0;i--){
		adjust(i,n);
	}
}
bool heap(){
	buildHeap();
	bool same=false;
	for(int i=n-1;i>0;i--){
		int tmp=t[i];
		t[i]=t[0];t[0]=tmp;
		adjust(0,i);
		if(same)
			return true;
		same=issame();
	}
	return false;
}
int main(){
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		t[i]=a[i];
	}
	for(int i=0;i<n;i++){
		scanf("%d",b+i);
	}
	
	if(insert()){
		printf("Insertion Sort\n");
	}else {
		for(int i=0;i<n;i++){
			t[i]=a[i];
		}
		if(heap())
			printf("Heap Sort\n");	
	}
	for(int i=0;i<n-1;i++)
		printf("%d ",t[i]);
	printf("%d",t[n-1]);
	getchar(); 
	getchar();
	return 0;
}