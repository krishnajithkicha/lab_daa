#include<iostream>
using namespace std;
void insertionsort(int ar[],int n){
	for(int i=1;i<n;i++){
		int key=ar[i];
		int j=i-1;
		while(j>=0 and ar[j]>key){
			ar[j+1]=ar[j];
			j--;
		}
		ar[j+1]=key;
	}
}
int main(){
	int ar[5]={5,4,1,3,2};
	insertionsort(ar,5);
	for(int k=0;k<5;k++){
		cout<<ar[k]<<" ";
	}
	cout<<endl;
	return 0;
}
