#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % n ;
    }
    auto start = high_resolution_clock::now();
    bubbleSort(arr, n);
    auto end = high_resolution_clock::now();
    auto time = duration_cast<milliseconds>(end - start);
    cout<<"Time is: "<<time.count() <<" milliseconds"<<endl;
    return 0;
}
