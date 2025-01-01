#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

void Insertion_Sort(long arr[], int n) {
    for(int i=1; i<n; ++i) {
        int temp = arr[i];
        int j = i-1;
        while(arr[j] > temp && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    for(int i=0; i<n; ++i) {
        cout<<arr[i] <<" "; 
    }
}

int main() {
    long  n;
    cout<<"Enter size: ";
    cin >> n;
    long arr[n];
    cout<<"Enter Elements: ";
    for(int i=0 ; i<n; ++i) {
        arr[i] =   rand() % n ;
    }
    auto start = high_resolution_clock::now();
    Insertion_Sort(arr, n);
    auto end = high_resolution_clock::now();
    auto time = duration_cast<milliseconds>(end - start);
    cout<<"\nThe Time is: "<<time.count() <<" milliseconds" <<endl;
}