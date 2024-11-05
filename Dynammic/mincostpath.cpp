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
int MinCostPath(int n,int m,int mat[100][100]){
	int F[n][m]={0};
	F[0][0]=mat[0][0];
	for(int k=1;k<n;k++){
		F[k][0]=F[k-1][0]+mat[k][0];
	}
	for(int l=1;l<m;l++){
		F[0][l]=F[0][l-1]+mat[0][l];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			F[i][j]=min(F[i-1][j-1],F[i-1][j],F[i][j-1])+mat[i][j];
		}
	}
	cout<<"The Matrix:"<<endl;
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			cout<<F[a][b]<<" ";
		}
		cout<<endl;
	}
	int B[6];
	int i=n-1,j=m-1,ind=0;
	B[ind++]=mat[i][j];
	while(i>0 || j>0){
		if(i>0 && j>0 && F[i][j]==F[i-1][j-1]+mat[i][j]){
			i--;
			j--;
		}
		else if(i>0 && F[i][j]==F[i-1][j]+mat[i][j]){
			i--;
		}
		else{
			j--;
		}
		B[ind++]=mat[i][j];
	}
	cout<<"The min cost path is:";
	for(int p=ind-1;p>=0;p--){
		cout<<B[p]<<"-";
	}
	cout<<endl;
	return F[n-1][m-1];
}
int main(){
	int n,m;
	cout<<"Enter the number of rows:";
	cin>>n;
	cout<<"Enter the number of columns:";
	cin>>m;
	int mat[100][100];
	cout<<"Enter the values:";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}
	int min=MinCostPath(n,m,mat);
	cout<<"The minimum cost is:"<<min<<endl;
}
