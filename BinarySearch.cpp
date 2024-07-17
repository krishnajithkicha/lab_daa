#include<iostream>
using namespace std;
int BinarySearch(int ar[],int val,int LB,int UB){
	int mid=(LB+UB)/2;
	int index=-1;
	if(ar[mid]==val){
		index=mid;
	}
	if(ar[mid]>val){
		BinarySearch(ar,val,LB,mid-1);
	}
	else if(ar[mid]<val){
		BinarySearch(ar,val,mid+1,UB);
	}
	return index;
}
int main(){
	int n;
	cout<<"Enter the number of elements:";
	cin>>n;
	int ar[n];
	cout<<"Enter sorted array:";
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	int key;
	cout<<"Enter the value to search:";
	cin>>key;
	int in=BinarySearch(ar,key,0,n);
	if(in==-1){
		cout<<"Element not found"<<endl;
	}
	else{
		cout<<"Element found at index:"<<in<<endl;
	}
	return 0;		
}
