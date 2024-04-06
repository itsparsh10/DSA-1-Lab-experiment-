// Menu driven linked list
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        cout << "Enter data: ";
        cin >> data;
        next = NULL;
    }
};
Node *createList(int n) 
{
    Node *start = NULL;
    Node *ptr = NULL;
    for (int i = 0; i < n; i++)
    {
        Node *new_node = new Node();
        if (start == NULL)
        {
            start = new_node;
            ptr = start;
        }
        else
        {
            ptr->next = new_node;
            ptr = new_node;
        }
    }
    return start;
}
void insertAtStart(Node *&a) 
{
    Node *new_node = new Node();
    if (new_node == NULL)
    {
        cout << "Overflow";
        return;
    }
    else
    {
        new_node->next = a;
        a = new_node;
    }
}
void insertAtEnd(Node *&a) 
{
    Node *new_node = new Node();
    Node *ptr = a;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = NULL;
}
void insertAfterElement(Node *&a) 
{
    int n;
    cout << "Enter element after which to add a node: ";
    cin >> n;
    Node *new_node = new Node();
    Node *ptr = a;
    if (new_node == NULL)
    {
        cout << "Overflow" << endl;
        return;
    }
    else
    {
        while (ptr->data != n)
        {
            ptr = ptr->next;
            if (ptr == NULL)
            {
                cout << "No element found" << endl;
                return;
            }
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
}
void insertBeforeElement(Node *&a) 
{
    int b;
    cout << "Enter element to add a node before it: ";
    cin >> b;
    Node *new_node = new Node();
    Node *ptr = a;
    if (new_node == NULL)
    {
        cout << "Overflow" << endl;
        return;
    }
    else
    {
        if (ptr->data == b)
        {
            new_node->next = ptr;
            a = new_node;
            return;
        }
        Node *preptr = ptr;
        ptr = ptr->next;
        while (ptr != NULL)
        {
            if (ptr->data == b)
            {
                new_node->next = ptr;
                preptr->next = new_node;
                return;
            }
            preptr = ptr;
            ptr = ptr->next;
        }
        cout << "Element not found" << endl;
    }
}
void deleteFirstNode(Node *&a) 
{
    Node *ptr = a;
    if (a == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        a = ptr->next;
        delete ptr;
    }
}
void deleteLastNode(Node *&a) 
{
    Node *ptr = a;
    Node *preptr = ptr;
    if (a == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (preptr == ptr) 
        {
            delete ptr;
            a = NULL;
        }
        else
        {
            preptr->next = NULL;
            delete ptr;
        }
    }
}
void deleteBeforeElement(Node *&a) 
{
    int b;
    cout << "Enter element to delete a node before it: ";
    cin >> b;
    Node *ptr = a;
    Node *preptr = NULL;
    Node *temp = a;
    if (a == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        if (a->data == b)
        {
            cout << "No element found" << endl;
            return;
        }
        while (ptr->data != b)
        {
            temp = preptr;
            preptr = ptr;
            ptr = ptr->next;
            if (ptr == NULL)
            {
                cout << "Element not found" << endl;
                return;
            }
        }
        if (preptr == NULL) 
        {
            cout << "Element not found" << endl;
        }
        else
        {
            if (preptr == a)
            {
                a = ptr;
            }
            else
            {
                temp->next = ptr;
            }
            delete preptr;
        }
    }
}
void deleteAfterElement(Node *&a) 
{
    int b;
    cout << "Enter element to delete node after: ";
    cin >> b;
    Node *ptr = a;
    Node *preptr = a;
    if (a == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else
    {
        while (preptr->data != b)
        {
            preptr = ptr;
            ptr = ptr->next;
            if (ptr == NULL)
            {
                cout << "Element not found" << endl;
                return;
            }
        }
        if (ptr == NULL)
        {
            cout << "Element not found" << endl;
        }
        else
        {
            if (ptr->next == NULL)
            {
                cout << "No element to delete" << endl;
            }
            else
            {
                preptr = ptr;
                ptr = ptr->next;
                preptr->next = ptr->next;
                delete ptr;
            }
        }
    }
}
void searchElement(Node *a, int b) 
{
    Node *ptr = a;
    Node *pos = NULL;
    while (ptr != NULL)
    {
        if (ptr->data == b)
        {
            pos = ptr;
            break;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    if (pos == NULL)
    {
        cout << "Element not found" << endl;
    }
    else
    {
        cout << "Element " << pos->data << " found at " << pos << endl;
    }
}
void showList(Node *a) 
{
    int count = 0;
    Node *ptr = a;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
        count++;
    }
    cout << endl
         << "Number of nodes: " << count << endl;
}
void deleteList(Node *&a) 
{
    Node *ptr = a;
    Node *temp = NULL;
    while (ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
    a = NULL;
}
int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    Node *start = createList(n);
    int choice;
    char ans = 'y';
    do
    {
        cout << "Enter your choice: \n1.Insert a node at beginning\n2.Insert a node at end\n3.Search the list for an element\n4.Insert a node after an element\n5.Insert a node before an element\n6.Delete first node\n7.Delete last node\n8.Delete a node after a particular element\n9.Delete a node before a particular element\n10.Show list\n11.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertAtStart(start);
            break;
        case 2:
            insertAtEnd(start);
            break;
        case 3:
            int element;
            cout << "Enter the element to search for: ";
            cin >> element;
            searchElement(start, element);
            break;
        case 4:
            insertAfterElement(start);
            break;
        case 5:
            insertBeforeElement(start);
            break;
        case 6:
            deleteFirstNode(start);
            break;
        case 7:
            deleteLastNode(start);
            break;
        case 8:
            deleteAfterElement(start);
            break;
        case 9:
            deleteBeforeElement(start);
            break;
        case 10:
            showList(start);
            break;
        case 11:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Wrong choice" << endl;
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> ans;
    } while (ans == 'y');
    deleteList(start);
    return 0;
}
