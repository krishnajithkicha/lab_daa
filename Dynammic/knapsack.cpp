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
int knapsack(int c,int n,int w[],int v[]){
	int F[n+1][c+1];
	for(int i=0;i<n+1;i++){
		F[i][0]=0;
	}
	for(int j=0;j<c+1;j++){
		F[0][j]=0;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<c+1;j++){
			if(j-w[i-1]>=0){
				F[i][j]=max(F[i-1][j],v[i-1]+F[i-1][j-w[i-1]]);
			}
			else{
				F[i][j]=F[i-1][j];
			}
		}
	}
	for(int i=0;i<n+1;i++){
		for(int j=0;j<c+1;j++){
			cout<<F[i][j]<<" ";
		}
		cout<<endl;
	}
	int B[10];
	int itc=0;
	int cp=c;
	for(int i=n;i>0;i--){
		if(F[i][cp]!=F[i-1][cp]){
			B[itc++]=i-1;
			cp-=w[i-1];
		}
	}
	cout<<endl;
	cout<<"Backtrack array";
	for(int i=itc-1;i>=0;i--){
		cout<<B[i]<<" ";
	}
	cout<<endl;
	return F[n][c];
}
int main(){
	int n,c;
	cout<<"Enter the number of items:";
	cin>>n;
	int v[n],w[n];
	cout<<"Enter the values:";
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	cout<<"Enter the weights:";
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	cout<<"Enter the capacity:";
	cin>>c;
	int k=knapsack(c,n,w,v);
	cout<<"max capacity:"<<k<<endl;
	return 0;
}
