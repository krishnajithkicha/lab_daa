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
	for(int i=1;i<m+1;i++){
		for(int j=1;j<n+1;j++){
			if(X[i-1]==Y[j-1]){
				F[i][j]=F[i-1][j-1]+1;
			}
			else{
				F[i][j]=max(F[i-1][j],F[i][j-1]);
			}
		}
	}
	cout<<"The Longest Common Subsequence matrix:"<<endl;
	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++){
			cout<<F[i][j]<<" ";
		}
		cout<<endl;
	}
	string lcs=" ";
	int k=m,l=n;
	while(k>0 and l>0){
		if(X[k-1]==Y[l-1]){
			lcs=X[k-1]+lcs;
			k--;
			l--;
		}
		else if(F[k-1][l]>F[k][l-1]){
			k--;
		}
		else{
			l--;
		}
	}
	cout<<"The length of the subsequence:"<<F[m][n]<<endl;
	return lcs;
}
int main(){
	string A,B;
	cout<<"Enter the first string:";
	cin>>A;
	cout<<"Enter the second string:";
	cin>>B;
	string lcs=LCS(A,B);
	cout<<"The Longest Common Subsequence is:"<<lcs<<endl;
	return 0;
}
