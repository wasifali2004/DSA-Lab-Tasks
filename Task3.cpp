#include <bits/stdc++.h>
using namespace std;

int check(int arr[], int target, int n) {
    for(int i=0; i<n; ++i) {
        if(target == arr[i]){
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[10] = {2,3,5,7,10,12,43,61,88,10};
    int target = 99;
    int n = sizeof(arr)/sizeof(0);
    int pos = check(arr, target, n);
    if(arr[pos] == target) {
        cout<<"Found At Position: " <<pos+1;
    }
    else{
        cout<<"Not Found!";
    }
}