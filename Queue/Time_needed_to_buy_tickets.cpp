#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, k;

    cout << "Enter number of people: ";
    cin >> n;

    int tickets[n];

    queue<int> q;

    cout << "Enter tickets required by each person:\n";

    for(int i=0;i<n;i++)
    {
        cin >> tickets[i];
        q.push(i);          // store person's index
    }

    cout << "Enter index of target person: ";
    cin >> k;

    int time = 0;

    while(!q.empty())
    {
        int person = q.front();
        q.pop();

        tickets[person]--;
        time++;

        if(tickets[person] > 0)
            q.push(person);

        if(person == k && tickets[person] == 0)
            break;
    }

    cout << "Time Needed = " << time << " seconds";

    return 0;
}