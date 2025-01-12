#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int mid, int e) {
    int a1 = mid - s + 1;
    int b2 = e - mid;
    int a[a1];
    int b[b2];
    for(int i=0; i<a1; ++i) {
        a[i] = arr[s+i];
    }
    for(int i=0; i<b2; ++i) {
        b[i] = arr[mid+i+1];
    }

    int i = 0, j = 0, k = s;
    while(i < a1 && j < b2) {
        if(a[i] > b[j]) {
            arr[k++] = b[j++];
        }
        else {
            arr[k++] = a[i++];
        }
    }

    while(i < a1) {
        arr[k++] = arr[i++];
    }
    
    while(j < b2) {
        arr[k++] = arr[j++];
    }
}

void merge_sort(int arr[], int s, int e) {
    if(s >= e) {
        return;
    }

    int mid = s+e/2;
    merge_sort(arr, s, mid);
    merge_sort(arr, mid+1, e);
    merge(arr, s, mid, e);
}

int main() {
    int arr[10];
    for(int i=0; i<10; ++i) {
        cin>>arr[i];
    }

    merge_sort(arr, 0, 10);

    for(int i=0; i<10; ++i) {
        cout<<arr[i] <<" ";
    }

    return 0;
}