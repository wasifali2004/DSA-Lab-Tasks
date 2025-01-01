#include <bits/stdc++.h>
using namespace std;

void recursive_varionacci_series(int n, int first, int second, int third, int count) {
    if(count >= n) {
        return ;
    }
    int next_second = first + second;
    int next_third = second + third;
    if(count < n) {
        cout << next_second <<" ";
        count++;
    }
    
    if(count < n) {
        cout << next_third <<" ";
        count++;
    }
    first = third;
    second = next_second;
    third = next_third;
    recursive_varionacci_series(n, first, second, third, count);
}

int main() {
    int n = 300;
    int first = 2;
    int second = 2;
    int third = 3;
    cout<<"----------------------------------------"<<endl;
    cout<< first <<" " <<second <<" "<<third <<" ";
    auto start = std::chrono::high_resolution_clock::now();

    recursive_varionacci_series(n, first, second, third, 3);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    cout << "\nTime taken: " << duration.count() << " ms " << endl;
    cout<<"-----------------------------------------"<<endl;
    
}


/*
void Varionacci_Series(int n) {
    int first = 2;
    int second = 2;
    int third = 3;
    cout<< first<<" " << second <<" " <<third <<" ";
    for (int i = 4; i <= n; ++i) {
        int next_second = first+second;
        cout<<next_second <<" ";

        int next_third = second+third;
        cout<<next_third <<" ";

        first = third;
        second = next_second;
        third = next_third;
    }
}
*/