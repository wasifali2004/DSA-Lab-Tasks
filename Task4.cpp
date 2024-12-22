#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    for(int i=0; i<5; ++i) {
        cin >>v[i];
    }
    int sum = 0 , maxi = INT_MIN;
    for(int i=0; i<5; ++i) { //KARDANE ALGORITHM
        sum += v[i];
        maxi = max(sum ,maxi);
        if(sum < 0) {
            sum = 0;
        }
    }
    cout<<maxi;

}