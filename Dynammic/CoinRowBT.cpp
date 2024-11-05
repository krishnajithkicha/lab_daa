#include<iostream>
using namespace std;
int max(int a,int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}
int CR(int C[],int n){
	int F[n+1];
	F[0]=0;
	F[1]=C[0];
	for(int i=2;i<n+1;i++){
		F[i]=max(F[i-1],F[i-2]+C[i-1]);
	}
	cout<<"Coin index array:";
	for(int i=0;i<n+1;i++){
		cout<<F[i]<<" ";
	}
	cout<<endl;
	cout<<"Selected coins:";
	int i=n;
	while(i>0){
		if(i==1 or F[i]!=F[i-1]){
			cout<<C[i-1]<<" ";
			i-=2;
		}
		else{
			i-=1;
		}
	}
	cout<<endl;
	return F[n];
}
int main(){
	int n;
	cout<<"Enter the number of coins:";
	cin>>n;
	int C[n];
	cout<<"Enter coins:";
	for(int i=0;i<n;i++){
		cin>>C[i];
	}
	int c=CR(C,n);
	cout<<"Max sum:"<<c<<endl;
	return 0;
}
