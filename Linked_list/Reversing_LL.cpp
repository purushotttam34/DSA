#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *head=NULL;

node* create_node(int n){
    node *newNode=new node;
    newNode->data=n;
    newNode->next=NULL;
    return newNode;
}

void insert_at_beginning(int value){
    node* newNode=create_node(value);
    newNode->next=head;

    head=newNode;
}
// Insert at End
void insert_at_end(int value)
{
    node *newNode = create_node(value);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    node *temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    cout << "Node inserted successfully.\n";
}

// Insert at Position
void insert_at_position(int value, int pos)
{
    if(pos <= 0)
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        insert_at_beginning(value);
        return;
    }

    node *temp = head;

    for(int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "Position Out of Range\n";
        return;
    }

    node *newNode = create_node(value);

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted successfully.\n";
}

// Delete from Beginning
void delete_beginning()
{
    if(head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    node *temp = head;

    head = head->next;

    delete temp;

    cout << "Node deleted successfully.\n";
}

// Delete from End
void delete_end()
{
    if(head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    if(head->next == NULL)
    {
        delete head;
        head = NULL;

        cout << "Node deleted successfully.\n";
        return;
    }

    node *temp = head;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;

    temp->next = NULL;

    cout << "Node deleted successfully.\n";
}

// Delete from Position
void delete_position(int pos)
{
    if(head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    if(pos <= 0)
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        delete_beginning();
        return;
    }

    node *temp = head;

    for(int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL)
    {
        cout << "Position Out of Range\n";
        return;
    }

    node *del = temp->next;

    temp->next = del->next;

    delete del;

    cout << "Node deleted successfully.\n";
}

// Display
void display()
{
    if(head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    node *temp = head;

    cout << "Linked List : ";

    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Search
void search(int key)
{
    node *temp = head;
    int pos = 1;

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            cout << "Element found at position " << pos << endl;
            return;
        }

        temp = temp->next;
        pos++;
    }

    cout << "Element not found.\n";
}

void reversed_linked_list(){
    if(head==NULL || head->next==NULL){
        display();
        return;
    }
    node *prev=NULL;
    node *current=head;
    node *next;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    display();
    
}

int main()
{
    int choice, value, position;

    do
    {
        cout << "\n===== Singly Linked List =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display\n";
        cout << "8. Search\n";
        cout << "9. Reverse the linked list\n";
        cout << "10. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter Value: ";
                cin >> value;
                insert_at_beginning(value);
                break;

            case 2:
                cout << "Enter Value: ";
                cin >> value;
                insert_at_end(value);
                break;

            case 3:
                cout << "Enter Value: ";
                cin >> value;
                cout << "Enter Position: ";
                cin >> position;
                insert_at_position(value, position);
                break;

            case 4:
                delete_beginning();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                cout << "Enter Position: ";
                cin >> position;
                delete_position(position);
                break;

            case 7:
                display();
                break;

            case 8:
                cout << "Enter Element to Search: ";
                cin >> value;
                search(value);
                break;

            case 9:
                cout << "Revrsed linked list is:\n";
                reversed_linked_list();
                break;
            
            case 10:
                cout<<"Program Ended\n";

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 10);

    return 0;
}