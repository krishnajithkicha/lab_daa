#include<iostream>
using namespace std;
int Fibonacci(int n){
	if(n<=1){
	    return 0;
	}
	if(n==2){
	    return 1;
	}
	if(n>2){
	    return Fibonacci(n-1)+Fibonacci(n-2);
	}
	return 0;
}
int main(){
	int n;
	cout<<"Enter the index of the fibonacci series to print:";
	cin>>n;
	cout<<n<<" term is:"<<Fibonacci(n)<<endl;
	return 0;
}
	 