#include<iostream>
using namespace std;
int partition(int n,int ar[]){
	int j=-1;
	int pivot=ar[n-1];
	int i=0;
	while(i<n){
		if(ar[i]<pivot){
			j=j+1;
			int tem=ar[i];
			ar[i]=ar[j];
			ar[j]=tem;
		}
	i++;
	}
	int te=ar[j+1];
	ar[j+1]=ar[n-1];
	ar[n-1]=te;
	return j+1;
}
void quicksort(int LB,int n,int ar[] ){
	if(LB<n){
		int p=partition(n,ar);
		quicksort(0,p-1,ar);
		quicksort(p+1,n,ar);
	}
}
int main(){
	int n;
	int ar[n];
	cout<<"Enter the number of elements:";
	cin>>n;
	for(int m=0;m<n;m++){
		cout<<"Enter the number:";
		cin>>ar[m];
	}
	quicksort(0,n,ar);
	for(int k=0;k<n;k++){
		cout<<ar[k]<<" ";
	}
	cout<<endl;
	return 0;
}
