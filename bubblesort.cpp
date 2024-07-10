#include<iostream>
using namespace std;
void bubblesort(int n,int ar[]){
	for(int i=0;i<n-1;i++){
	     for(int j=0;j<n-i-1;j++){
	     	if(ar[j]>ar[j+1]){
	     		int t=ar[j];
	     		ar[j]=ar[j+1];
	     		ar[j+1]=t;
	     	}
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
	bubblesort(n,ar);
	cout<<endl;
	return 0;
}
