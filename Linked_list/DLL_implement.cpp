#include<iostream>
using namespace std;

struct node
{
    int data;
    node *prev;
    node *next;
};

node *head = NULL;

// Create Node
node* create_node(int value)
{
    node *newNode = new node;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert at Beginning
void insert_beginning(int value)
{
    node *newNode = create_node(value);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert at End
void insert_end(int value)
{
    node *newNode = create_node(value);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    node *temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at Position
void insert_position(int value, int pos)
{
    if(pos == 1)
    {
        insert_beginning(value);
        return;
    }

    node *temp = head;

    for(int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
    {
        cout << "Invalid Position\n";
        return;
    }

    node *newNode = create_node(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
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

    if(head != NULL)
        head->prev = NULL;

    delete temp;
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
        return;
    }

    node *temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;

    delete temp;
}

// Delete at Position
void delete_position(int pos)
{
    if(head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    if(pos == 1)
    {
        delete_beginning();
        return;
    }

    node *temp = head;

    for(int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
    {
        cout << "Invalid Position\n";
        return;
    }

    temp->prev->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

// Forward Traversal
void forward_display()
{
    node *temp = head;

    cout << "Forward : ";

    while(temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Backward Traversal
void backward_display()
{
    if(head == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    node *temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    cout << "Backward : ";

    while(temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }

    cout << "NULL\n";
}

int main()
{
    insert_beginning(20);
    insert_beginning(10);
    insert_end(30);
    insert_end(40);
    insert_position(25,3);

    forward_display();
    backward_display();

    delete_beginning();
    forward_display();

    delete_end();
    forward_display();

    delete_position(2);
    forward_display();

    return 0;
}