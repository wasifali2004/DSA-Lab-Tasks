#include <bits/stdc++.h>
using namespace std;

int Insert_At_End(int arr[], int n, int ele,int ele2, int size) {
    if( n+2 >= size) {
        return n;
    }
    else {
        arr[n] = ele;
        arr[n+1] = ele2;
        return (n+2);
    }
}

int main() {
    int arr[20] = {2,36,10,33,37,54,87,66,6};
    int n = 9;
    int ele = 55;
    int size = sizeof(arr)/sizeof(0);
    cout<<"Before Insertion: ";
    for(int i=0; i<n; ++i) {
        cout<<arr[i] <<" ";
    }
    n = Insert_At_End(arr, n, ele, 11, size);
    cout<<"\nAfter Insertion: ";
    for(int i=0; i<n; ++i) {
        cout<<arr[i] <<" "; 
    }
}