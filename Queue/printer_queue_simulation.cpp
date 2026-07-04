#include <iostream>
#include <string>
using namespace std;

#define MAX 5

class PrinterQueue
{
private:
    string job[MAX];
    int front, rear;

public:
    PrinterQueue()
    {
        front = rear = -1;
    }

    void addJob(string name)
    {
        if (rear == MAX - 1)
        {
            cout << "Printer Queue Full!\n";
            return;
        }

        if (front == -1)
            front = 0;

        job[++rear] = name;
        cout << "Print Job \"" << name << "\" Added.\n";
    }

    void printJob()
    {
        if (front == -1 || front > rear)
        {
            cout << "No Print Jobs Available.\n";
            return;
        }

        cout << "Printing: " << job[front] << endl;
        front++;

        if (front > rear)
            front = rear = -1;
    }

    void nextJob()
    {
        if (front == -1)
            cout << "No Print Jobs.\n";
        else
            cout << "Next Job: " << job[front] << endl;
    }

    void displayJobs()
    {
        if (front == -1)
        {
            cout << "Printer Queue is Empty.\n";
            return;
        }

        cout << "\nPending Print Jobs:\n";

        for (int i = front; i <= rear; i++)
            cout << i - front + 1 << ". " << job[i] << endl;
    }

    void isEmpty()
    {
        if (front == -1)
            cout << "Printer Queue is Empty.\n";
        else
            cout << "Printer Queue is Not Empty.\n";
    }

    void isFull()
    {
        if (rear == MAX - 1)
            cout << "Printer Queue is Full.\n";
        else
            cout << "Printer Queue is Not Full.\n";
    }
};

int main()
{
    PrinterQueue pq;

    int choice;
    string name;

    do
    {
        cout << "\n===== Printer Queue =====\n";
        cout << "1. Add Print Job\n";
        cout << "2. Print Next Job\n";
        cout << "3. View Next Job\n";
        cout << "4. Display All Jobs\n";
        cout << "5. Check Empty\n";
        cout << "6. Check Full\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter Document Name: ";
            getline(cin, name);
            pq.addJob(name);
            break;

        case 2:
            pq.printJob();
            break;

        case 3:
            pq.nextJob();
            break;

        case 4:
            pq.displayJobs();
            break;

        case 5:
            pq.isEmpty();
            break;

        case 6:
            pq.isFull();
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}