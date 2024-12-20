#include<iostream>
#include<limits>
using namespace std;
int min(int p,int q){
	if(p<q){
		return p;
	}
	else{
		return q;
	}
}
int coinchange(int Ac[],int amount,int nc){
	int F[amount+1];
	F[0]=0;
	for(int i=1;i<=amount;i++){
		int temp=numeric_limits<int>::max()-1;
		int j=0;
		while(j<nc and i>=Ac[j]){
			temp=min(F[i-Ac[j]],temp);
			j++;
		}
		F[i]=temp+1;
	}
	for(int k=0;k<=amount;k++){
		cout<<F[k]<<" ";
	}
	cout<<endl;
	int bal=amount;
	int B[amount+1];
	int ind=0;
	while(bal>0){
		for(int j=0;j<nc;j++){
			if(bal>=Ac[j] && F[bal]==F[bal-Ac[j]]+1){
				B[ind++]=Ac[j];
				bal-=Ac[j];
			}
		}	
	}
	cout<<"Coins used for minimum change: ";
    for(int i=0;i<ind;i++) {
        cout<<B[i]<<" ";
    }
	cout<<endl;
	return F[amount];
}
int main(){
	int n;
	cout<<"Enter the number of denominations:";
	cin>>n;
	int A[n];
	cout<<"Enter the denominations:";
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	int sum;
	cout<<"Enter the sum:";
	cin>>sum;
	int coins=coinchange(A,sum,n);
	cout<<"Number of coins:"<<coins<<endl;
	return 0;
} 
