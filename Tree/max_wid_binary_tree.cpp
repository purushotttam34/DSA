#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Structure of a Binary Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to find maximum width of binary tree
int maxWidth(Node *root)
{
    if (root == NULL)
        return 0;

    queue<pair<Node *, long long>> q;
    q.push({root, 0});

    int ans = 0;

    while (!q.empty())
    {
        int size = q.size();
        long long first = q.front().second;
        long long last = first;

        for (int i = 0; i < size; i++)
        {
            Node *current = q.front().first;
            long long index = q.front().second - first;
            q.pop();

            last = index;

            if (current->left)
                q.push({current->left, 2 * index + 1});

            if (current->right)
                q.push({current->right, 2 * index + 2});
        }

        ans = max(ans, (int)(last + 1));
    }

    return ans;
}

int main()
{
    /*
            1
          /   \
         3     2
        / \     \
       5   3     9

    Maximum Width = 4
    */

    Node *root = new Node(1);

    root->left = new Node(3);
    root->right = new Node(2);

    root->left->left = new Node(5);
    root->left->right = new Node(3);

    root->right->right = new Node(9);

    cout << "Maximum Width of Binary Tree = " << maxWidth(root);

    return 0;
}