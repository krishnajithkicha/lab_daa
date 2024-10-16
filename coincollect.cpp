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
int coinCollection(int c[5][6]){
	int F[5][6]={0};
	F[0][0]=c[0][0];
	for(int k=1;k<5;k++){
		F[k][0]=F[k-1][0]+c[k][0];
	}
	for(int l=1;l<6;l++){
		F[0][l]=F[0][l-1]+c[0][l];
	}
	for(int i=1;i<5;i++){
		for(int j=1;j<6;j++){
			F[i][j]=max(F[i][j-1],F[i-1][j])+c[i][j];
		}
	}
	for(int m=0;m<5;m++){
		for(int n=0;n<6;n++){
			cout<<F[m][n]<<" ";
		}
		cout<<endl;
	}
	return F[4][5];
}
int main(){
	int m,n;
	cout<<"Enter number of rows:";
	cin>>m;
	cout<<"Enter number of cols:";
	cin>>n;
	int c[5][6];
	cout<<"Enter the values:";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>c[i][j];
		}
	}
	int coin=coinCollection(c);
	cout<<"the maximum no of coins:"<<coin<<endl;
	return 0;
}
