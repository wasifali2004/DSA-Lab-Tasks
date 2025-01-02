#include <bits/stdc++.h>
using namespace std;

class BST{
    public:
    int n;
    BST* lchild;
    BST* rchild;
    BST() {}
    BST(int val) {
        n = val;
        lchild = rchild = NULL;
    }
};


    /*
    void insertion(int x){
        BST* bst = new BST(x);
        if(root == NULL) {
            root = bst;
        }
        else {
            BST* tmp = root;
            while(tmp != NULL) {
                if(x > root -> n){
                    tmp = root -> rchild;
                }
            }
        }
    }
    */

    BST* recursive_insert(BST* tmp, int x){
        if(tmp == NULL) {
            return new BST(x);
        }
        else if(x > tmp -> n){
            tmp -> rchild = recursive_insert(tmp -> rchild, x);
        }
        else {
            tmp -> lchild = recursive_insert(tmp -> lchild, x);
        }
        return tmp;
    }

    void inorder_recursive_display(BST* tmp) {
        if(tmp != NULL) {
            inorder_recursive_display(tmp->lchild);
            cout<<tmp -> n <<" ";
            inorder_recursive_display(tmp -> rchild);
        }
    }


void minimum(BST* tmp) {
    if(tmp -> lchild == NULL) {
        cout<<"\nMinimum value is: "<<tmp -> n <<endl;
    }
    minimum(tmp -> lchild);
}

int maximum(BST* tmp) {
    
    while(tmp -> rchild != NULL) {
        tmp = tmp -> rchild;
    }
    cout<<"Maximum value: "<<tmp -> n <<endl;
    return tmp -> n;

}

bool search(BST* tmp, int x) {
    if(tmp != NULL) {
        if(x == tmp -> n) {
            return true;
        }
        else if(x > tmp -> n) {
            search(tmp -> rchild, x);
        }
        else {
            search(tmp -> lchild, x);
        }
    }
    return true;
}


void postorder_recursive_display(BST* tmp) {
        if(tmp != NULL) {
            postorder_recursive_display(tmp->lchild);
            postorder_recursive_display(tmp -> rchild);
            cout<<tmp -> n <<" ";
        }
}

int main() {

    BST* root = new BST (20);
    BST* tmp = root;
    recursive_insert(tmp, 10);
    recursive_insert(tmp, 9);
    recursive_insert(tmp, 16);
    recursive_insert(tmp, 18);
    recursive_insert(tmp, 28);
    recursive_insert(tmp, 25);
    recursive_insert(tmp, 29);
    recursive_insert(tmp, 30);
    inorder_recursive_display(tmp);
    cout<<endl;
    postorder_recursive_display(tmp);
    cout<<"\n" <<search(tmp ,15);
    minimum(tmp);
    cout<<maximum(tmp);
    
}