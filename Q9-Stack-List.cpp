#include <iostream>
using namespace std;

class Node {
public:
    int element;
    Node *next;

    Node() {
        cout << "Enter element: ";
        cin >> element;
        next = nullptr;
    }
};

void pushList(Node *&a) {
    Node *newnode = new Node();
    if (a == nullptr) {
        a = newnode;
    } else {
        newnode->next = a;
        a = newnode;
    }
    cout << "Element pushed successfully\n";
}

void popList(Node *&a) {
    if (a == nullptr) {
        cout << "Stack is empty\n";
    } else {
        Node *ptr = a;
        cout << "Element " << a->element << " popped successfully\n";
        a = a->next;
        delete ptr;
    }
}

void peekList(Node *&a) {
    if (a == nullptr) {
        cout << "Stack is empty\n";
    } else {
        cout << "Top element: " << a->element << endl;
    }
}

void seeList(Node *&a) {
    Node *ptr = a;
    if (a == nullptr) {
        cout << "Empty stack\n";
    } else {
        while (ptr) {
            cout << ptr->element << endl;
            ptr = ptr->next;
        }
    }
}

int main() {
    Node *top = nullptr;
    int choice;
    while (true) {
        cout << "\nStack operation:\n1.Push\n2.Pop\n3.Peek\n4.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                pushList(top);
                break;
            case 2:
                popList(top);
                break;
            case 3:
                peekList(top);
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Wrong choice\n";
                break;
        }
    }
}
