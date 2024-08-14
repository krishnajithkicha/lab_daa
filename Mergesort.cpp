#include<iostream>
#include<limits>
#include<cstring>
using namespace std;
void merge(int A[],int LB,int mid,int UB){
	int n1=mid-LB+1;
	int n2=UB-mid;
	int L[n1+1];
	int R[n2+1];
	memcpy(L,&A[LB],n1*sizeof(int));
	memcpy(R,&A[mid+1],n2*sizeof(int));
	L[n1]=R[n2]=numeric_limits<int>::max();
	int i=0,j=0,k=LB;
	for(k=LB;k<=UB;k++){
		if(L[i]<R[j]){
			A[k]=L[i];
			i++;
		}
		else{
			A[k]=R[j];
			j++;
		}
	}
}
void mergesort(int ar[],int LB,int UB){
	if(LB<UB){
		int M=(LB+UB)/2;
		mergesort(ar,LB,M);
		mergesort(ar,M+1,UB);
		merge(ar,LB,M,UB);
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
	cout<<"Enter the elements:";
	for(int i=0;i<len;i++){
		cin>>Arr[i];
	}
	mergesort(Arr,0,len);
	cout << "Sorted array is \n";
    display(Arr,len);
    return 0;
}
