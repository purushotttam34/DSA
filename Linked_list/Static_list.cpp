#include <iostream>
using namespace std;

const int MAX = 100;

int main() {
    int arr[MAX];
    int n = 0;     // Empty list
    int choice;

    do {
        cout << "\n----- Static List -----\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Traverse\n";
        cout << "4. Search\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            if (n == MAX) {
                cout << "List Overflow!\n";
                break;
            }

            int pos, value;

            cout << "Enter position (1-" << n + 1 << "): ";
            cin >> pos;

            if (pos < 1 || pos > n + 1) {
                cout << "Invalid Position!\n";
                break;
            }

            cout << "Enter value: ";
            cin >> value;

            for (int i = n; i >= pos; i--)
                arr[i] = arr[i - 1];

            arr[pos - 1] = value;
            n++;

            cout << "Element inserted successfully.\n";
            break;
        }

        case 2: {
            if (n == 0) {
                cout << "List Underflow!\n";
                break;
            }

            int pos;

            cout << "Enter position to delete: ";
            cin >> pos;

            if (pos < 1 || pos > n) {
                cout << "Invalid Position!\n";
                break;
            }

            for (int i = pos - 1; i < n - 1; i++)
                arr[i] = arr[i + 1];

            n--;

            cout << "Element deleted successfully.\n";
            break;
        }

        case 3: {
            if (n == 0) {
                cout << "List is Empty.\n";
                break;
            }

            cout << "Elements: ";

            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";

            cout << endl;
            break;
        }

        case 4: {
            if (n == 0) {
                cout << "List is Empty.\n";
                break;
            }

            int key;
            bool found = false;

            cout << "Enter element to search: ";
            cin >> key;

            for (int i = 0; i < n; i++) {
                if (arr[i] == key) {
                    cout << "Element found at position " << i + 1 << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Element not found.\n";

            break;
        }

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}