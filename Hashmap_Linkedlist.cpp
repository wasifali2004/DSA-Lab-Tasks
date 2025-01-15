#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

class LinkList{
    private: 
    Node* head; 
    public:
    LinkList(){
        head = NULL;
    }
    void insertAthead(int d){
        Node* newNode = new Node(d);
        newNode->next = head;
        head = newNode;
    }
    void search(int key){
        Node* curr = head;
        while(curr!=NULL){
            if(curr->data == key){
                cout<<curr->data<<" found"<<endl;
                return;
            }
            curr = curr->next;

        }
        cout<<"Not found"<<endl;
    }
    void delteNode(int key){
        if(key == head->data){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* curr = head;
        Node* pre = NULL;
        while(curr && curr->data != key){
            pre = curr;
            curr = curr->next;
        }
        if(curr==NULL){
            cout<<"not found"<<endl;
            return;
        }
        pre->next = curr->next;
    }
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<" "<<temp->data;
            temp = temp->next;
        }
    }

};

class Hashtable{
    private:
    int size;
    LinkList* arr;
    public:
    Hashtable(int s){
        size = s;
        arr = new LinkList[s];
        for(int i =0; i<size; i++){
            arr[i] = LinkList(); //create empty linklists
        }
    }
    int hashFunction(int data){
        return data%size;
    }
    void insert(int data){
        int index = hashFunction(data);
        arr[index].insertAthead(data);
    }
    void search(int key){
        int index = hashFunction(key);
        arr[index].search(key);
    }
    void deleteData(int key){
        int index = hashFunction(key);
        arr[index].delteNode(key);
    }
    void display(){
        for(int i =0; i<size; i++){
            cout<<"Bucket "<<i<<" : ";
            arr[i].display();
            cout<<endl;
        }
    }
};


int main(){

    Hashtable ht(10); //create array of size 10
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.display();
    return 0;
}