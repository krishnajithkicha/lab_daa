#include<iostream>
using namespace std;
void insertionsort(int ar[],int n){
	int i=1;
	while(i<n){
		int j=i-1;
		while(j<n){
			if(ar[j]>ar[j]){
				int t=ar[j];
				ar[j]=ar[i];
				ar[i]=t;
			}
		j++;
		}
	i++;
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
