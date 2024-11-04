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
string LCS(string X,string Y){
	int m=X.length();
	int n=Y.length();
	int F[m+1][n+1];
	for(int i=0;i<=m;i++){
		F[i][0]=0;
	}
	for(int j=0;j<=n;j++){
		F[0][j]=0;
	}
	for(int k=1;k<=m;k++){
		for(int l=1;l<=n;l++){
			if(X[k-1]==Y[l-1]){
				F[k][l]=F[k-1][l-1]+1;
			}
			else{
				F[k][l]=max(F[k-1][l],F[k][l-1]);
			}
		}
	}
	int i=m,j=n;
	string lcs=" ";
	while(i>0 && j>0){
		if(X[i-1]==Y[j-1]){
			lcs=X[i-1]+lcs;
			i--;
			j--;
		}
		else if(F[i-1][j]>F[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}
	cout<<"length:"<<F[m][n]<<endl;
	for(int o=0;o<=m;o++){
		for(int p=0;p<=n;p++){
			cout<<F[o][p]<<" ";
		}
		cout<<endl;
	}
	return lcs;
}
int main(){
    string A = "ABCBDAB";
    string B = "BDCAB";
    string Lcs=LCS(A,B);
    cout<<"Subsequence:"<<Lcs<<endl;
    return 0;
}
