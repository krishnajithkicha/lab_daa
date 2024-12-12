#include<iostream>
using namespace std;

void Swap(int i,int j,int Arr[]){
	int temp=Arr[i];
	Arr[i]=Arr[j];
	Arr[j]=temp;
}
void Heapify(int Arr[],int i,int n){
	int largest=i;   
	int l=2*i+1;
	int r=2*i+2;
	if (Arr[largest]<Arr[l] and l<n){
		largest=l;
	}
	if(Arr[largest]<Arr[r] and r<n){
		largest=r;
	}
	if(largest!=i){
		Swap(i,largest,Arr);
		Heapify(Arr,largest,n);
	}	
}
void Heapsort(int Arr[],int n){
	for(int i=(n-2)/2;i>=0;i--){
		Heapify(Arr,i,n);
	}
	for(int i=n-1;i>0;i--){
		Swap(0,i,Arr);
		Heapify(Arr,0,i);
	}
}

int main(){
	
	int len;
	cout<<"Enter the length of array:";
	cin>>len;
	int Arr[len];
	cout<<"Enter the elements:"<<endl;
	for(int i=0;i<len;i++){
		cin>>Arr[i];
	}
	Heapsort(Arr,len);
	cout<<"HeapSorted Array:"<<endl;
	for(int i=0;i<len;i++){
		cout<<Arr[i]<<" ";
	}
	cout<<endl;
}
