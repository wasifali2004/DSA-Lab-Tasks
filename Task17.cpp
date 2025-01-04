#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int n;
    Node(int x) {
        n = x;
        left = right = NULL;
    }
};

Node* recSearchItem(Node* root, int key) {
    if (root == NULL || root->n == key) {
        return root;
    }
    if (root->n < key) {
        return recSearchItem(root->right, key);
    }
    return recSearchItem(root->left, key);
}

Node* insertNode(Node* root, int key) {
    if (root == NULL) {
        return new Node(key);
    }
    if (key < root->n) {
        root->left = insertNode(root->left, key);
    } else {
        root->right = insertNode(root->right, key);
    }
    return root;
}

int main() {
    Node* root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    int key = 40;
    Node* result = recSearchItem(root, key);

    if (result != NULL) {
        cout << "Node with value " << key << " found in the BST." << endl;
    } else {
        cout << "Node with value " << key << " not found in the BST." << endl;
    }

    return 0;
}
