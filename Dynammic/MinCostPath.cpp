#include<iostream>
using namespace std;
int min(int a,int b,int c){
	if(a<b and a<c){
		return a;
	}
	else if(b<a and b<c){
		return b;
	}
	else{
		return c;
	}
}
int MinCostPath(int mat[4][3]){
	int F[4][3]={0};
	F[0][0]=mat[0][0];
	for(int k=1;k<4;k++){
		F[k][0]=F[k-1][0]+mat[k][0];
	}
	for(int l=1;l<3;l++){
		F[0][l]=F[0][l-1]+mat[0][l];
	}
	for(int i=1;i<4;i++){
		for(int j=1;j<3;j++){
			F[i][j]=min(F[i-1][j-1],F[i-1][j],F[i][j-1])+mat[i][j];
		}
	}
	for(int m=0;m<4;m++){
		for(int n=0;n<3;n++){
			cout<<F[m][n]<<" ";
		}
		cout<<endl;
	}
	return F[4][3];
}
int main(){
	int mat[4][3];
	cout<<"Enter the values:";
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			cin>>mat[i][j];
		}
	}
	MinCostPath(mat);
}
