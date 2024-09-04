#include<iostream>
using namespace std;
void swap(int a[],int p,int q){
    int t=a[p];
    a[p]=a[q];
    a[q]=t;
}
void bubblesort(int n, int ar[]) {
    for (int i=0;i<n-1;i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (ar[j] > ar[j+1]) {
                swap(ar,j,j+1);
            }
        }
    }
    for (int k = 0; k < n; k++) {
        cout << ar[k] << " ";
    }
}
int main() {
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int ar[n];
    for(int l=0;l<n;l++){
    	cout<<"Enter number:";
    	cin>>ar[l];
	}
    bubblesort(n, a r);
    return 0;
}

