#include<iostream>
using namespace std;
void selectionsort(int ar[],int n){
	for(int i=0;i<n;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(ar[min]>ar[j]){
				int t=ar[j];
				ar[j]=ar[min];
				ar[min]=t;
			}
		}
		if(min!=i){
			int tem=ar[min];
			ar[min]=ar[i];
			ar[i]=tem;
		}
	}
	cout<<"The sorted array:";
	 for(int k=0;k<n;k++){
	 	cout<<ar[k]<<" ";
	 }
}
int main(){
	int ar[100];
	int n;
	cout<<"Enter the number of elements:";
	cin>>n;
	for(int m=0;m<n;m++){
		cout<<"Enter the number:";
		cin>>ar[m];
	}
	selectionsort(ar,n);
	cout<<endl;
	return 0;
}
