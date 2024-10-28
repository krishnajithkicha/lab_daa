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
int knapsack(int W,int weight[],int val[],int n){
	int F[n+1][W+1];
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=W+1;j++){
			if(i==0 || j==0){
				F[i][j]=0;
			}
			else if(weight[i-1]<=j){
				F[i][j]=max(F[i-1][j],val[i-1]+F[i-1][j-weight[i-1]]);
			}
			else{
				F[i][j]=F[i-1][j];
			}
		}
	}
	for(int k=0;k<n+1;k++){
		for(int l=0;l<W+1;l++){
			cout<<F[k][l]<<" ";
		}
		cout<<endl;
	}
	return F[n][W];
}
int main(){
	int W=5;
	int val[]={12,10,20,15};
	int weight[]={2,1,3,2};
	int n=4;
	int max=knapsack(W,weight,val,n);
	cout<<max<<endl;
}
