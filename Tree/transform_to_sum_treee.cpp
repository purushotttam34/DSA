#include <iostream>
using namespace std;

// Structure of Binary Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to convert Binary Tree into Sum Tree
int convertToSumTree(Node *root)
{
    // Base Case
    if (root == NULL)
        return 0;

    // Store original value
    int oldValue = root->data;

    // Convert left and right subtrees
    int leftSum = convertToSumTree(root->left);
    int rightSum = convertToSumTree(root->right);

    // Update current node
    root->data = leftSum + rightSum;

    // Return total sum of subtree
    return root->data + oldValue;
}

// Inorder Traversal
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    /*
              10
             /  \
           -2    6
           / \   / \
          8 -4  7  5
    */

    Node *root = new Node(10);

    root->left = new Node(-2);
    root->right = new Node(6);

    root->left->left = new Node(8);
    root->left->right = new Node(-4);

    root->right->left = new Node(7);
    root->right->right = new Node(5);

    cout << "Original Tree (Inorder): ";
    inorder(root);

    convertToSumTree(root);

    cout << "\nSum Tree (Inorder): ";
    inorder(root);

    return 0;
}