#easy short
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
int knp(int c,int n,int v[],int w[]){
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
	cout<<"Knapsack matrix:"<<endl;
	for(int i=0;i<n+1;i++){
		for(int j=0;j<c+1;j++){
			cout<<F[i][j]<<" ";
		}
		cout<<endl;
	}
	int items[n];
	int ind=0;
	int cap=c;
	for(int i=n;i>0;i--){
		if(F[i][cap]!=F[i-1][cap]){
			items[ind++]=i-1;
			cap=cap-w[i-1];
		}
	}
	cout<<"Included Items:"<<endl;
	for(int i=ind-1;i>=0;i--){
		cout<<items[i]<<" ";
	}
	cout<<endl;
	return F[n][c];
}
int main(){
	int n;
	cout<<"Enter the number of items:";
	cin>>n;
	int c;
	cout<<"Enter the capacity:";
	cin>>c;
	int v[n];
	cout<<"Enter the values:";
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int w[n];
	cout<<"Enter the weights:";
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	int kp=knp(c,n,v,w);
	cout<<"Max capacity:"<<kp<<endl;
	return 0;
}
