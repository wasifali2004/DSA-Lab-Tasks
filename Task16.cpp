#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    Node* pre;
    int data;
    Node(int n) {
        data = n;
        next = nullptr;
        pre = nullptr;
    }
};

class circular_doublylist {
private:
    Node* head;
public:
    circular_doublylist() {
        head = nullptr;
    }

    void insertion(int x) {
        Node* new_node = new Node(x);
        if (head == nullptr) {
            head = new_node;
            head->next = head;
            head->pre = head;
        } else {
            Node* tail = head->pre;
            new_node->next = head;
            new_node->pre = tail;
            head->pre = new_node;
            tail->next = new_node;
        }
    }

    void deletion(int x) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* tmp = head;
        do {
            if (tmp->data == x) {
                if (tmp->next == tmp) {
                    head = nullptr;
                } else {
                    tmp->pre->next = tmp->next;
                    tmp->next->pre = tmp->pre;
                    if (tmp == head) {
                        head = tmp->next;
                    }
                }
                delete tmp;
                return;
            }
            tmp = tmp->next;
        } while (tmp != head);
        cout << "Not found!" << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* tmp = head;
        do {
            cout << tmp->data << " ";
            tmp = tmp->next;
        } while (tmp != head);
        cout << endl;
    }

    void reverse_display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* tmp = head -> pre;
        do {
            cout << tmp->data << " ";
            tmp = tmp->pre;
        } while (tmp != head -> pre);
        cout << endl;
    }

    bool search(int x) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return false;
        }
        Node* tmp = head;
        do {
            if (tmp->data == x) {
                cout << "Found " << x << " in the list." << endl;
                return true;
            }
            tmp = tmp->next;
        } while (tmp != head);  
        cout << x << " not found in the list." << endl;
        return false;
    }

};

int main() {
    circular_doublylist obj;
    obj.insertion(10);
    obj.insertion(20);
    obj.insertion(30);
    obj.insertion(40);
    obj.insertion(50);
    obj.insertion(60);
    obj.deletion(50);
    obj.display();
    obj.reverse_display();
    cout<<obj.search(30);
}
