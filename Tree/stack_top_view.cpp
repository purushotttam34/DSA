#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

// Binary Tree Node
struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to return Top View
vector<int> topView(Node *root) {
    vector<int> ans;

    if (root == NULL)
        return ans;

    // Map: Horizontal Distance -> Node Value
    map<int, int> mp;

    // Queue: Node + Horizontal Distance
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        Node *temp = q.front().first;
        int hd = q.front().second;
        q.pop();

        // Store only first node at each horizontal distance
        if (mp.find(hd) == mp.end())
            mp[hd] = temp->data;

        if (temp->left)
            q.push({temp->left, hd - 1});

        if (temp->right)
            q.push({temp->right, hd + 1});
    }

    // Store answer from leftmost to rightmost
    for (auto x : mp)
        ans.push_back(x.second);

    return ans;
}

int main() {
    /*
            1
          /   \
         2     3
          \   / \
           4 5   6
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    vector<int> result = topView(root);

    cout << "Top View: ";
    for (int x : result)
        cout << x << " ";

    return 0;
}