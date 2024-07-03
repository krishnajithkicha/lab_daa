#include<iostream>
using namespace std;
class Array{
	public:
	int LB=0,UB;
	int A[100];
	Array(int ub){
		LB=0;
		UB=ub;
		for(int i=0;i<UB;i++){
			cout<<"Enter elements:";
			cin>>A[i];
		}
	}
	void display(){
		cout<<"The elements are:";
		for(int j=0;j<UB;j++){
		    cout<<A[j]<<" ";
		}
		cout<<endl;
	}
	void LinearSearch(int u,int val){
		int count=0;
		for(int k=0;k<u;k++){
			if(A[k]==val){
				cout<<"Element found at index "<<k<<endl;
				count++;
			}
			
		}
		if(count==0){
			cout<<"Element not found"<<endl;
		}
	}
};
int main(){
	int n;
	cout<<"Enter number of elements:";
	cin>>n;
	Array a(n);
	a.display();
	int x;
	cout<<"Enter the value to search:";
	cin>>x;
	a.LinearSearch(n,x);
	return 0;
}
