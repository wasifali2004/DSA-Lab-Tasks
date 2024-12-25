#include <bits/stdc++.h>
using namespace std;

class Book {
    private:
    float price[3];
    string author[3];
    string tittle[3];
    int count = 0;
    public:
    Book(float p, string s, string c) {
        price[count++] = p;
        author[count++] = s;
        tittle[count++] = c;
    }
    void sort() {
        for(int i=0; i<3; ++i) {
            for(int j=i+1; j<3; ++j) {
                if(price[i] > price[j]) {
                    swap(price[j], price[i]);
                }
                else {
                    if(author[i] > author[j]) {
                        swap(author[j], author[i]);
                    }
                }
            }
        }
    }
    void display() {
            cout<<"Price is: "<<price <<endl;
            cout<<"Author is: "<<author <<endl;
            cout<<"Tittle is: "<<tittle <<endl;
            cout<<"-----------------------" <<endl;
    }
};


int main() {
    Book obj[] = {
        Book(100.5, "Wasif", "C++"),
        Book(44.2, "Bilawal", "JS"),
        Book(353.3, "Ali", "C")
    };
    int n = sizeof(obj)/sizeof(obj[0]);
    for(int i=0; i<n; ++i) {
        obj[i].display();
    }
}