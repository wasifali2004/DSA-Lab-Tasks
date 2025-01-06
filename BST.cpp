#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int n;
    Node(int val) {
        this -> n = val;
        left = right = NULL;
    }
};

class tree {
    private:
    Node* root;
    public:
    tree(): root(NULL) {}

    void insert(int x) {
        Node* new_node = new Node(x);
        if(root == NULL) {
            root = new_node;
        }
        else {
            Node* temp = root;
            Node* parent = NULL;
            while(temp != NULL) {
                parent = temp;
                if(temp -> n > new_node -> n) {
                    temp = temp -> left;
                }
                else if(temp -> n < new_node -> n) {
                    temp = temp -> right;
                }
                else {
                    cout<<"Value already exist!";
                }
            }

            if(new_node -> n > parent -> n) {
                parent -> right = new_node;
            }
            else {
                parent -> left = new_node;
            }
        }
    }

        Node* recursive_insert(int x, Node* root) {
            if(root == NULL) {
                return new Node(x);
            }
            if(root -> n > x) {
                root -> left = recursive_insert(x, root -> left);
            }
            else {
                root -> right = recursive_insert(x, root -> right);
            }

            return root;
        }

        Node* deletion(int x) {
            Node* new_node = new Node(x);
            if(root == NULL) {
                return root;
            }
            else {
                Node* curr = root; 
                Node* parent = root;
                bool isleft = false;
                while(curr != NULL) {
                    parent = curr;
                    if(curr -> n > new_node -> n) {
                        curr = curr -> left;
                        isleft = true;
                    }
                    else {
                        curr = curr -> right;
                        isleft = false;
                    }
                }
                if(curr == NULL) {
                    cout<<"Value not Found!";
                }

                if(curr -> left == NULL && curr -> right == NULL) {
                    if(curr == root) {
                        root = NULL;
                    }
                    else if(isleft) {
                        curr -> left = NULL;
                    }
                    else {
                        curr -> right = NULL;
                    }
                }

                else if(curr -> left == NULL) {
                    if(curr == root){
                        root = curr -> right;
                    }
                    else if(isleft) {
                        parent -> left = curr -> right;
                    }
                    else {
                        parent -> right = curr -> right;
                    }
                }
                
                else if(curr -> right == NULL) {
                    if(curr == root) {
                        root = curr -> left;
                    }
                    else if(isleft) {
                        parent -> left = curr -> left;
                    }
                    else {
                        parent -> right = curr -> left;
                    }
                }
                
                else {
                    Node* successor = get_successor(curr);
                    if(curr == root) {
                        root = successor;
                    }
                    else if(isleft) {
                        parent -> left = successor;
                    }
                    else {
                        parent -> right = successor;
                    }
                    successor -> left = curr -> left;
                    delete curr;
                }
            }
        return root;
    }

    Node* get_successor(Node* del) {
        Node* succ = del -> right;
        Node* parent_succ = root;
        while(succ -> left != NULL) {
            parent_succ = succ;
            succ = succ -> left;
        }

        if(succ != del -> right) {
            parent_succ = succ -> right;
            succ -> right = del -> right;
        }

        return succ;
    } 

    Node* find_leaf_node(Node* root) {
        if(root == NULL) {
            return root; 
        }
        find_leaf_node(root -> left);
        if(root -> left == NULL && root -> right == NULL) {
            cout<<"Leaf Node!";
        }
        find_leaf_node(root -> right);
    }
 
};