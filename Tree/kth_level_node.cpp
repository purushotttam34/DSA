#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to print all nodes at Kth level
void kthLevel(Node* root, int k) {
    if (root == NULL)
        return;

    if (k == 1) {
        cout << root->data << " ";
        return;
    }

    kthLevel(root->left, k - 1);
    kthLevel(root->right, k - 1);
}

int main() {

    // Creating the tree
    /*
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int k;
    cout << "Enter the level: ";
    cin >> k;

    cout << "Nodes at Level " << k << " : ";
    kthLevel(root, k);

    return 0;
}