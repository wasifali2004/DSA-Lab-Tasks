#include <bits/stdc++.h>
using namespace std;

class Stack{
    private:
    int arr[10];
    int top;
    public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if(top < 9) {
            arr[++top] = x;
            cout<<"Value " <<x <<" is inserted at position: "<<top << endl;
        }
        else {
            cout<<"Stack is Full!" <<endl;
        }
    }

    int pop() {
        if(top > -1) {
            return arr[top--];
        }
        else {
            cout<<"Stack is Empty!"<<endl;
        }
    }

    void display() {
    if(top == -1)  {
        cout<<"Stack is empty!" <<endl;
    }
    else {
        cout<<"Elements are: ";
        for(int i = top; i>=0; --i) {
            cout<<arr[i];
        }
    }
}    
};


int main() {
    Stack obj;
    obj.push(10);
    obj.push(30);
    obj.push(20);
    obj.push(40);
    obj.push(50);
    obj.push(60);
    obj.push(70);
    obj.push(80);
    obj.push(90);
    obj.push(100);
    obj.display();
    return 0;
}