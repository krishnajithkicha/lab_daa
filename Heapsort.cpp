#include<iostream>
using namespace std;
void swap(int p,int q,int ar[]){
	int temp=ar[p];
	ar[p]=ar[q];
	ar[q]=temp;
}
void Heapify(int i,int n,int ar[]){
	int large=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if(ar[large]<ar[l] && l<n){
		large=l;
	}
	if(ar[large]<ar[r] && r<n){
		large=r;
	}
	if(large!=i){
		swap(i,large,ar);
		Heapify(large,n,ar);
	}
}
void Heapsort(int ar[],int n){
	for(int i=(n-2)/2;i>=0;i--){
		Heapify(i,n,ar);
	}
	for(int i=n-1;i>0;i--){
		swap(0,i,ar);
		Heapify(0,i,ar);
	}
}
void display(int ar[],int n){
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
}
int main(){
	int len;
	cout<<"Enter the length of array:";
	cin>>len;
	int Arr[len];
	cout<<"Enter the elements one by one:"<<endl;
	for(int i=0;i<len;i++){
		cin>>Arr[i];
	}
	Heapsort(Arr,len);
	cout << "Sorted array is \n";
    display(Arr,len);
    return 0;
}
	

