#include <bits/stdc++.h>
using namespace std;

class Dequeue{
    private:
    int arr[10];
    int front;
    int rear;
    int count;
    public:
    Dequeue() {
        for(int i=0; i<10; ++i) {
            arr[i] = -1;
        }
        front = 0;
        rear = -1;
        count = 0;
    } 

    void InsertRear(int x) {
        if(count < 9) {
            arr[++rear] = x;
            cout<<x <<" inserted at left side of the queue with: "<<"Rear: "<<rear <<" "<<"Front: "<<front <<endl;
            count++;
        }
        else {
            cout<<"Queue is Full!" <<endl;
        }
    } 

    void InsertFront(int y) {
        if(count < 9) {
            front = (front - 1 + 10) % 10;
            arr[front] = y;
            cout<<y <<" inserted at left side of the queue with: "<<"Rear: "<<rear <<" "<<"Front: " <<front <<endl;
            count++;
        }
        else {
            cout<<"Queue is Full!" <<endl;
        }
    }

    int RemoveRear() {
        if(count == 0) {
           cout<<"Queue is Empty!" <<endl;
        }
        count--;
        int ans = arr[rear];
        arr[rear] = -1;
        rear--;
        return ans;
    }

    int RemoveFront() {
        if(count == 0) {
           cout<<"Queue is Empty!" <<endl;
        }
        count--;
        int ans = arr[front];
        arr[front] = -1;
        front++;
        return ans;
    }

    void display() {
        cout<<"Index\t\t Value\t\t Pointer"<<endl;
        for(int i=0; i<10; ++i) {
            if(arr[i] == -1) {
                cout<<i <<"\t\t "<<"Empty" <<"\t\t "<< ( i == rear ? "Rear" : (i == front ? "Front" : "") ) << endl;
            }
            else {
            cout<<i <<"\t\t "<<arr[i] <<"\t\t "<< ( i == rear ? "Rear" : (i == front ? "Front" : "") ) << endl;
            }
        } 
    }

};

int main() {
    Dequeue dq;
    int options = 0;
    while(options != -1){
    cout<<"------------------------------------------" <<endl;
    cout<<"Please enter a number representing an operation in the following list (-1 to quit):\n 1.InsertRear()\n 2.InsertFront\n 3.RemoveRear()\n 4.RemoveFront()\n 5.Display()"<<endl;
    cin >> options;
    int n;
    cout<<"User Enters: "<<options <<endl;
    switch (options) {
            case 1:
                cout << "Enter a value that you want to insert at rear: ";
                cin >> n;
                dq.InsertRear(n);
                break;
            case 2:
                cout << "Enter a value that you want to insert at front: ";
                cin >> n;
                dq.InsertFront(n);
                break;
            case 3:
                cout << "Removed from rear: " << dq.RemoveRear() << endl;
                break;
            case 4:
                cout << "Removed from front: " << dq.RemoveFront() << endl;
                break;
            case 5:
                dq.display();
                break;
            default:
                cout << "Invalid option, please try again." << endl;
                break;
        }
    }

}