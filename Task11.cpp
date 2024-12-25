#include <bits/stdc++.h>
using namespace std;

void Bubble_Sort(string arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Optimize_Bubble_Sort(string arr[], int n) {
    bool check = false;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                check = true;
            }
        }
        if (!check) {
            break;
        }
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    string* arr = new string[n];
    cout << "Enter " << n << " strings:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    Bubble_Sort(arr, n);
    cout << "----------------------------" << endl;
    cout << "Bubble Sort Implemented:  ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n----------------------------" << endl;

    Optimize_Bubble_Sort(arr, n);
    cout << "----------------------------" << endl;
    cout << "Optimize Bubble Sort Implemented:  ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n----------------------------" << endl;

    delete[] arr;
    return 0;
}
