#include<iostream>
using namespace std;
int max(int p,int q){
	int m;
	if(p>q){
	   m=p;
	}
	else if(q>p){
	   m=q;
	}
	else{
	   m=p;
	}
	return m;
}
int Coinrow(int Ac[],int n){
	int F[n+1];
	F[0]=0;
	F[1]=Ac[0];
	for(int i=2;i<n+1;i++){
		F[i]=max(Ac[i-1]+F[i-2],F[i-1]);
	}
	for(int j=0;j<n+1;j++){
		cout<<F[j]<<endl;
	}
	return F[n];	
}
int main(){
	int n;
	cout<<"Enter the number of coins:";
	cin>>n;
	int coin[n];
	cout<<"Enter the different coins:";
	for(int i=0;i<n;i++){
		cin>>coin[i];
	}
	cout<<"The maximum sum of the coins are:"<<Coinrow(coin,n)<<endl;
	return 0;
}
	