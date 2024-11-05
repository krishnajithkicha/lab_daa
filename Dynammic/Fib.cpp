#include<iostream>
using namespace std;
int Fib(int n){
	if(n<=1){
		return n;
	}
	int fib[n+1];
	fib[0]=0;
	fib[1]=1;
	for(int i=2;i<n+1;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	return fib[n];
}
int main(){
	int n;
	cout<<"Enter the term:";
	cin>>n;
	int F=Fib(n);
	cout<<"The "<<n<<"th term in fibonacci series is:"<<F<<endl;
	return 0;
}
