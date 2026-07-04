#include <iostream>
using namespace std;

#define MAX 5

class Queue
{
private:
    int q[MAX];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int x)
    {
        if (rear == MAX - 1)
        {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        q[rear] = x;

        cout << x << " inserted into queue." << endl;
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << q[front] << " deleted from queue." << endl;
        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }

    void Front()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is Empty." << endl;
        }
        else
        {
            cout << "Front Element = " << q[front] << endl;
        }
    }

    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is Empty." << endl;
            return;
        }

        cout << "Queue Elements: ";

        for (int i = front; i <= rear; i++)
        {
            cout << q[i] << " ";
        }

        cout << endl;
    }

    void size()
    {
        if (front == -1 || front > rear)
        {
            cout << "Size = 0" << endl;
        }
        else
        {
            cout << "Size = " << rear - front + 1 << endl;
        }
    }

    void isEmpty()
    {
        if (front == -1 || front > rear)
            cout << "Queue is Empty." << endl;
        else
            cout << "Queue is Not Empty." << endl;
    }

    void isFull()
    {
        if (rear == MAX - 1)
            cout << "Queue is Full." << endl;
        else
            cout << "Queue is Not Full." << endl;
    }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\n===== Linear Queue Menu =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Display" << endl;
        cout << "5. Size" << endl;
        cout << "6. isEmpty" << endl;
        cout << "7. isFull" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.Front();
            break;

        case 4:
            q.display();
            break;

        case 5:
            q.size();
            break;

        case 6:
            q.isEmpty();
            break;

        case 7:
            q.isFull();
            break;

        case 8:
            cout << "Program Terminated." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 8);

    return 0;
}