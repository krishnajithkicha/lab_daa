#include<iostream>
using namespace std;
int BinarySearch(int ar[],int val,int LB,int UB){
	int index=-1;
	if(LB<UB){
		int mid=(LB+UB)/2;
		return index;
		if(ar[mid]==val){
			return mid;
		}
		if(ar[mid]>val){
			UB=mid-1;
			return BinarySearch(ar,val,LB,UB);
		}
		else if(ar[mid]<val){
			LB=mid+1;
			return BinarySearch(ar,val,LB,UB);
		}
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
	int in=BinarySearch(ar,key,0,n-1);
	if(in==-1){
		cout<<"Element not found"<<endl;
	}
	else{
		cout<<"Element found at index:"<<in<<endl;
	}
	return 0;		
}
