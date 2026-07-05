#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    queue<int> q;
    stack<int> s;

    int n, k, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter queue elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push(x);
    }

    cout << "Enter value of K: ";
    cin >> k;

    if (k > n || k <= 0)
    {
        cout << "Invalid value of K";
        return 0;
    }

    // Step 1: Push first K elements into stack
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Push stack elements back to queue
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move remaining elements to rear
    for (int i = 0; i < n - k; i++)
    {
        q.push(q.front());
        q.pop();
    }

    // Display Queue
    cout << "Queue after reversing first " << k << " elements:\n";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}