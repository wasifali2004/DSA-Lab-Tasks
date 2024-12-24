#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int n;
    Node* next;
    Node(int val) {
        n = val;
        next = NULL;
    }
};


void InsertAtTail(Node* &tail, int n) {
    Node* new_node = new Node(n);
    tail -> next = new_node;
    tail = new_node;
}

void InsertAtHead(Node* &head, int n) {
    Node* new_node = new Node(n);
    if(head == NULL) {
        head = new_node;
    }
    else {
        new_node -> next = head;
        head = new_node;
    }
}

void InsertAtPosition(Node* &head, int pos, int x) {
    Node* tmp = head;
    Node* new_node = new Node(x);
    int count = 1;
    while(tmp != NULL) {
        if(count == (pos-1)) {
            new_node -> next = tmp -> next;
            tmp -> next = new_node;
            tmp = new_node;
            break;
        }
        tmp = tmp -> next;
        count++;
    }
}

void display(Node* &head) {
    Node* tmp = head;
    cout<<"NULL";
    while(tmp != NULL) {
        cout<< tmp->n <<"->";
        tmp = tmp -> next;
    }
    cout<<"NULL";
}

int count_nodes(Node* &head) {
    Node* tmp = head;
    int count = 0;
    while(tmp != NULL) {
        tmp = tmp -> next;
        count++;
    }
    return count;
}

int main() {
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    InsertAtHead(head, 5);
    InsertAtTail(tail, 10);
    InsertAtTail(tail, 20);
    InsertAtHead(head, 30);
    InsertAtPosition(head, 3, 99);
    display(head);
    cout<<"\nTotal Nodes are: "<<count_nodes(head);
}