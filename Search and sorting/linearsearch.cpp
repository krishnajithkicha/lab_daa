#include<iostream>
using namespace std;
int LinearSearch(int n,int A[],int key){
	int ind=-1;
	for(int i=0;i<n;i++){
		if(A[i]==key){
			ind=i;
			return ind;
			break;
		}
	}
	return ind;
}
int main(){
	int n;
	cout<<"Enter the number of elements:";
	cin>>n;
	int A[n];
	cout<<"Enter the elements for array:";
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	int key;
	cout<<"Enter the key to search:";
	cin>>key;
	int ls=LinearSearch(n,A,key);
	if(ls!=-1){
		cout<<"The element "<<key<< " found at index "<<ls<<endl;
	}
	else{
		cout<<"The element not found"<<endl;
	}
	return 0;
}
