#include<iostream>
using namespace std;
void Heapsort(int ar[],int n){
	for(int i=n/2;i>0;i--){
		Heapify(i,n,ar);
	}
	for(int i=0;i>0;i--){
		swap(0,n-1,ar);
		Heapify((n-i)/2,n-i,ar);
	}
}
void Heapify(int ar[],){
	for(
	int i=(n-2)/2; //index of last leaf node
	if(ar[i]<ar[2*i+1]){
		swap(i,2*i+1,ar);
	}
	else if(ar[i]<ar[2*i+2]){
		swap(i,2*i+2,ar);
	}
	else{
		
		
}
void swap(int p,int q,int ar[]){
	int temp=ar[p];
	ar[p]=ar[q];
	ar[q]=temp;
}
int main(){
	
