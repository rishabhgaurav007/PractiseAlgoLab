#include<stdio.h>

void quick(int a[],int l,int u){
	int k;
	if(l<u){
		
		k=partition(a,l,u);
		quick(a,l,k-1);
		quick(a,k+1,u);
	}
	return;
}
int partition(int a[],int l,int u){
	int v=a[l];
	int i=l,j=u+1,temp;
	do{
		do{
			i++;
		}while(i<=u&&a[i]<v);
		do{
			j--;
		}while(a[j]>v);
		if(i<j){
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}
	}while(i<j);
	a[l]=a[j];
	a[j]=v;
	return j;
}
int main(){
	int i,a[]={25,8,120,80,5,9,10,150,200};
	for(i=0;i<=8;i++)
	printf("%d ",a[i]);
	quick(a,0,8);
	for(i=0;i<=8;i++)
	printf("%d ",a[i]);
	return 0;
}
