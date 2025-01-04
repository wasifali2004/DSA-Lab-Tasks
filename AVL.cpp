#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
using namespace std;

class Node {
public:
    int key;
    float data;
    int height;

    Node* leftChild;
    Node* rightChild;

    Node(int k, float d) {
        key = k;
        data = d;
        height = 0;
        leftChild = NULL;
        rightChild = NULL;
    }

    void display() {
        cout << "Key = " << key << ", Data = " << data << " ,Height = " << height << endl;
    }
};

class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = NULL;
    }

    int avlHeight(Node* curr) {
        if (curr == NULL)
            return -1;
        return (1 + max(avlHeight(curr->leftChild), avlHeight(curr->rightChild)));
    }

    int BF(Node* curr) {
        int hl, hr;
        if (curr == NULL)
            return 0;
        if (curr->leftChild == NULL)
            hl = 0;
        else
            hl = 1 + curr->leftChild->height;

        if (curr->rightChild == NULL)
            hr = 0;
        else
            hr = 1 + curr->rightChild->height;
        return (hl - hr);
    }

    Node* rightRotate(Node* x) {
        Node* y;
        y = x->leftChild;
        x->leftChild = y->rightChild;
        y->rightChild = x;

        x->height = avlHeight(x);
        y->height = avlHeight(y);
    
        return y;
    }

    Node* leftRotate(Node* x) {
        Node* y;
        y = x->rightChild;
        x->rightChild = y->leftChild;
        y->leftChild = x;

        x->height = avlHeight(x);
        y->height = avlHeight(y);
        return y;
    }

    Node* RL(Node* T) {
        T->rightChild = rightRotate(T->rightChild);
        T = leftRotate(T);
        return T;
    }

    Node* LR(Node* T) {
        T->leftChild = leftRotate(T->leftChild);
        T = rightRotate(T);
        return T;
    }

    Node* avlInsert(Node* croot, int key, float data) {
        if (croot == NULL) {
            croot = new Node(key, data);
        } else {
            if (key > croot->key) {
                croot->rightChild = avlInsert(croot->rightChild, key, data);
                if (BF(croot) == -2) {
                    if (key > croot->rightChild->key) {
                        croot = leftRotate(croot);
                    } else {
                        croot = RL(croot);
                    }
                }
            } else if (key < croot->key) {
                croot->leftChild = avlInsert(croot->leftChild, key, data);
                if (BF(croot) == 2) {
                    if (key < croot->leftChild->key) {
                        croot = rightRotate(croot);
                    } else {
                        croot = LR(croot);
                    }
                }
            }
        }
        croot->height = avlHeight(croot);
        return croot;
    }

    Node* avlDelete(Node* croot, int key) {
        if (croot == NULL) return NULL;

        if (key < croot->key) {
            croot->leftChild = avlDelete(croot->leftChild, key);
        } else if (key > croot->key) {
            croot->rightChild = avlDelete(croot->rightChild, key);
        } else {
            if (croot->leftChild == NULL) {
                Node* temp = croot->rightChild;
                delete croot;
                croot = temp;
            } else if (croot->rightChild == NULL) {
                Node* temp = croot->leftChild;
                delete croot;
                croot = temp;
            } else {
                Node* successor = getSuccessor(croot);
                croot->key = successor->key;
                croot->data = successor->data;
                croot->rightChild = avlDelete(croot->rightChild, successor->key);
            }
        }

        if (croot == NULL) return croot;

        croot->height = avlHeight(croot);

        int balance = BF(croot);
        if (balance > 1 && BF(croot->leftChild) >= 0) {
            return rightRotate(croot);
        }
        if (balance > 1 && BF(croot->leftChild) < 0) {
            croot->leftChild = leftRotate(croot->leftChild);
            return rightRotate(croot);
        }
        if (balance < -1 && BF(croot->rightChild) <= 0) {
            return leftRotate(croot);
        }
        if (balance < -1 && BF(croot->rightChild) > 0) {
            croot->rightChild = rightRotate(croot->rightChild);
            return leftRotate(croot);
        }

        return croot;
    }

    Node* getSuccessor(Node* node) {
        Node* current = node->rightChild;
        while (current->leftChild != NULL) {
            current = current->leftChild;
        }
        return current;
    }

    void deleteNode(int key) {
        root = avlDelete(root, key);
    }

    void inOrderTraversal(Node* localRoot) {
        if (localRoot != NULL) {
            inOrderTraversal(localRoot->leftChild);
            cout << localRoot->key << "\t";
            inOrderTraversal(localRoot->rightChild);
        }
    }

    void Avg_Del_Time(int n) {
        vector<int> keys;
        srand(time(0));
        collectKeys(root, keys);

        int successfulDeletions = 0;
        double totalTime = 0.0;

        for (int i = 0; i < n; ++i) {
            if (keys.empty()) break;

            int randomIndex = rand() % keys.size();
            int keyToDelete = keys[randomIndex];

            auto start = chrono::high_resolution_clock::now();
            root = avlDelete(root, keyToDelete);
            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double, milli> deletionTime = end - start;

            if (!isNodePresent(root, keyToDelete)) {
                totalTime += deletionTime.count();
                successfulDeletions++;
                keys.erase(keys.begin() + randomIndex);
            }
        }

        if (successfulDeletions > 0) {
            double avgTime = totalTime / successfulDeletions;
            cout << "Average Deletion Time for " << successfulDeletions << " deletions: " << avgTime << " ms" << endl;
        } else {
            cout << "No successful deletions performed." << endl;
        }
    }

private:
    void collectKeys(Node* node, vector<int>& keys) {
        if (node != NULL) {
            collectKeys(node->leftChild, keys);
            keys.push_back(node->key);
            collectKeys(node->rightChild, keys);
        }
    }

    bool isNodePresent(Node* node, int key) {
        if (node == NULL) return false;
        if (key < node->key) return isNodePresent(node->leftChild, key);
        if (key > node->key) return isNodePresent(node->rightChild, key);
        return true;
    }
};

int main() {
    AVLTree* tree = new AVLTree();

    tree->root = tree->avlInsert(tree->root, 20, 1.0);
    tree->root = tree->avlInsert(tree->root, 10, 1.1);
    tree->root = tree->avlInsert(tree->root, 30, 1.2);
    tree->root = tree->avlInsert(tree->root, 5, 1.3);
    tree->root = tree->avlInsert(tree->root, 15, 1.4);
    tree->root = tree->avlInsert(tree->root, 25, 1.5);
    tree->root = tree->avlInsert(tree->root, 35, 1.6);
    tree->root = tree->avlInsert(tree->root, 3, 1.7);
    tree->root = tree->avlInsert(tree->root, 7, 1.8);

    cout << "In Order Traversing: " << endl;
    tree->inOrderTraversal(tree->root);
    cout << endl;

    tree->Avg_Del_Time(5);

    cout << "In Order Traversing: " << endl;
    tree->inOrderTraversal(tree->root);
    cout << endl;

    return 0;
}
