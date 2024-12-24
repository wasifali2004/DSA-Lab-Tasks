#include <iostream>
using namespace std;

class Dequeue {
private:
    int arr[10]; // Array to hold the elements
    int front;   // Index of the front element
    int rear;    // Index of the rear element
    int count;   // Count of current elements

public:
    Dequeue() {
        // Initialize the array to indicate all positions are empty
        for (int i = 0; i < 10; i++) {
            arr[i] = -1; // Using -1 to indicate empty slots
        }
        front = 0; // Front starts at 0
        rear = -1; // Rear starts before the first element
        count = 0; // No elements initially
    }

    void InsertRear(int x) {
        if (count == 10) {
            cout << "Queue is Full!" << endl; // Check if full
            return;
        }
        rear = (rear + 1) % 10; // Increment rear with wraparound
        arr[rear] = x;          // Insert at rear
        count++;                // Increment count
        cout << x << " inserted at rear.  Rear=" << rear << "  Front=" << front << endl;
    }

    void InsertFront(int y) {
        if (count == 10) {
            cout << "Queue is Full!" << endl; // Check if full
            return;
        }
        front = (front - 1 + 10) % 10; // Decrement front with wraparound
        arr[front] = y;                // Insert at front
        count++;                        // Increment count
        cout << y << " inserted at front.  Rear=" << rear << "  Front=" << front << endl;
    }

    int RemoveRear() {
        if (count == 0) {
            cout << "Queue is Empty!" << endl; // Check if empty
            return -1; // Return a sentinel value
        }
        int removedValue = arr[rear]; // Get the value
        arr[rear] = -1;                // Mark as empty
        rear = (rear - 1 + 10) % 10;   // Decrement rear with wraparound
        count--;                       // Decrement count
        return removedValue;           // Return the removed value
    }

    int RemoveFront() {
        if (count == 0) {
            cout << "Queue is Empty!" << endl; // Check if empty
            return -1; // Return a sentinel value
        }
        int removedValue = arr[front]; // Get the value
        arr[front] = -1;                // Mark as empty
        front = (front + 1) % 10;       // Increment front with wraparound
        count--;                        // Decrement count
        return removedValue;            // Return the removed value
    }

    void display() {
        cout << "Index\tValue\tPointer" << endl;
        for (int i = 0; i < 10; ++i) {
            if (arr[i] == -1) {
                cout << i << "\tEmpty" << "\t" << endl;
            } else {
                cout << i << "\t" << arr[i] << "\t" << (i == rear ? "Rear" : (i == front ? "Front" : "")) << endl;
            }
        }
    }
};

int main() {
    Dequeue dq;
    int options;
    while (true) {
        cout << "Please enter a number representing an operation in the following list (-1 to quit):\n"
             << "1. InsertRear()\n"
             << "2. InsertFront()\n"
             << "3. RemoveRear()\n"
             << "4. RemoveFront()\n"
             << "5. Display()" << endl;
        cin >> options;

        if (options == -1) {
            break; // Exit loop if user enters -1
        }

        int n;
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
    return 0;
}