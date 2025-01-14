#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int height;
    Node *left;
    Node *right;
    Node() {};
    Node(int d)
    {
        data = d;
        right = left = NULL;
        height = 0;
    }
    ~Node()
    {
        cout << "\nNode with data " << data << " deleted" << endl;
    }
};

class AVL
{
public:
    Node *root;
    AVL()
    {
        root = NULL;
    }

    int getHeight(Node *currRoot)
    {
        if (currRoot == NULL)
        {
            return -1;
        }
        return (1+max(getHeight(root->left),getHeight(root->right)));
    }

    int BF(Node *currRoot)
    {
        if (currRoot == NULL)
        {
            return 0;
        }
        return (getHeight(currRoot->left) - getHeight(currRoot->right));
    }

    Node *leftRotate(Node *currRoot)
    {
        Node *y = currRoot->right;
        Node *temp = y->left;
        y->left = currRoot;
        currRoot->right = temp;
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        currRoot->height = 1 + max(getHeight(currRoot->left), getHeight(currRoot->right));
        return y;
    }

    Node *rightRotate(Node *currRoot)
    {
        Node *y = currRoot->left;
        Node *temp = y->right;
        y->right = currRoot;
        currRoot->left = temp;
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        currRoot->height = 1 + max(getHeight(currRoot->left), getHeight(currRoot->right));
        return y;
    }

    Node *LeftRightRotate(Node *currRoot)
    {
        currRoot->left = leftRotate(currRoot->left);
        return rightRotate(currRoot);
    }
    Node *RightLeftRotate(Node *currRoot)
    {
        currRoot->right = rightRotate(currRoot->right);
        return leftRotate(currRoot);
    }

    Node *insert(Node *currRoot, Node *new_node)
    {
        if (currRoot == NULL)
        {
            cout << "\nNode with data " << new_node->data << " inserted" << endl;
            return new_node;
        }
        if (new_node->data < currRoot->data)
        {
            cout << "\nAs " << new_node->data << " < " << currRoot->data << " so moving to left" << endl;
            currRoot->left = insert(currRoot->left, new_node);
        }
        else if (new_node->data > currRoot->data)
        {
            cout << "\nAs " << new_node->data << " > " << currRoot->data << " so moving to right" << endl;
            currRoot->right = insert(currRoot->right, new_node);
        }
        else
        {
            cout << "\nA node with data " << new_node->data << " already exists in the tree" << endl;
            return currRoot;
        }

        currRoot->height = getHeight(currRoot);

        int balanceFactor = BF(currRoot);
        if (balanceFactor > 1 && new_node->data < currRoot->left->data)
        {
            cout<<"\nRight Rotaion performed on "<<currRoot->data<<endl;
            return rightRotate(currRoot);
        }
        if (balanceFactor > 1 && new_node->data > currRoot->left->data)
        {
             cout<<"\nLeft-Right Rotaion performed on "<<currRoot->data<<endl;
            return LeftRightRotate(currRoot);
        }
        if (balanceFactor < -1 && new_node->data > currRoot->right->data)
        {
             cout<<"\nLeft Rotaion performed on "<<currRoot->data<<endl;
            return leftRotate(currRoot);
        }
        if (balanceFactor < -1 && new_node->data < currRoot->right->data)
        {
             cout<<"\nRight-Left Rotaion performed on "<<currRoot->data<<endl;
            return RightLeftRotate(currRoot);
        }
        return currRoot;
    }

    Node *search(Node *currRoot, int key)
    {
        if (currRoot == NULL || currRoot->data == key)
        {
            return currRoot;
        }
        else if (key > currRoot->data)
        {
            return search(currRoot->right, key);
        }
        else
        {
            return search(currRoot->left, key);
        }
    }

    Node *findSuccessor(Node *curr)
    {
        while (curr != NULL && curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr;
    }

    Node *deleteNode(Node *currRoot, int key)
    {
        if (currRoot == NULL)
        {
            return currRoot;
        }

        if (currRoot->data == key)
        {
            cout << "\nA node with data " << key << " was found in the tree and now deleting....." << endl;

            // Case 1: No children (leaf node)
            if (currRoot->right == NULL && currRoot->left == NULL)
            {
                delete currRoot;
                return NULL;
            }
            // Case 2: One child (right child only)
            else if (currRoot->left == NULL)
            {
                Node *temp = currRoot->right;
                delete currRoot;
                return temp;
            }
            // Case 2: One child (left child only)
            else if (currRoot->right == NULL)
            {
                Node *temp = currRoot->left;
                delete currRoot;
                return temp;
            }
            // Case 3: Two children
            else
            {
                Node *inorderSuccessor = findSuccessor(currRoot->right);
                currRoot->data = inorderSuccessor->data;
                currRoot->right = deleteNode(currRoot->right, inorderSuccessor->data);
                return currRoot;
            }
        }
        else if (key < currRoot->data)
        {
            cout << "\nAs " << key << " < " << currRoot->data << " so moving to left" << endl;
            currRoot->left = deleteNode(currRoot->left, key);
        }
        else if (key > currRoot->data)
        {
            cout << "\nAs " << key << " > " << currRoot->data << " so moving to right" << endl;
            currRoot->right = deleteNode(currRoot->right, key);
        }

        currRoot->height = getHeight(currRoot);

        int balanceFactor = BF(currRoot);
        if (balanceFactor > 1 && getHeight(currRoot->left) >= 0)
        {
             cout<<"\nRight Rotaion performed"<<endl;
            return rightRotate(currRoot);
        }
        if (balanceFactor > 1 && getHeight(currRoot->left) < 0)
        {
             cout<<"\nLeft-Right Rotaion performed"<<endl;
            return LeftRightRotate(currRoot);
        }
        if (balanceFactor < -1 && getHeight(currRoot->right) <= 0)
        {
             cout<<"\nLeft Rotaion performed"<<endl;
            return leftRotate(currRoot);
        }
        if (balanceFactor < -1 && getHeight(currRoot->right) > 0)
        {
             cout<<"\nRight-Left Rotaion performed"<<endl;
            return RightLeftRotate(currRoot);
        }

        return currRoot;
    }

    void inorderTraversal(Node *currRoot)
    {
        if (currRoot == NULL)
        {
            return;
        }
        inorderTraversal(currRoot->left);
        cout << " " << currRoot->data;
        inorderTraversal(currRoot->right);
    }
};


int main(){

    AVL tree;
    tree.root = tree.insert(tree.root,new Node(50));
    tree.root = tree.insert(tree.root,new Node(17));
    tree.root = tree.insert(tree.root,new Node(76));
    tree.root = tree.insert(tree.root,new Node(9));
    tree.root = tree.insert(tree.root,new Node(14));
    tree.root = tree.insert(tree.root,new Node(12));
    tree.root = tree.insert(tree.root,new Node(23));
    tree.root = tree.insert(tree.root,new Node(19));
    tree.root = tree.insert(tree.root,new Node(54));
    tree.root = tree.insert(tree.root,new Node(72));
    tree.root = tree.insert(tree.root,new Node(67));
    tree.inorderTraversal(tree.root);
    return 0;
}