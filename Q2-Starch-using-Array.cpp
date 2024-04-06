// Implement Stack ADT using array.
#include <iostream>
using namespace std;
#define max_size 100

class Stack {
    int top;
    int arr[max_size];
public:
    Stack(){
        top-1;
    }
    bool empty(){
        return top==-1;
    }
    bool full(){
        return top==max_size - 1;
    }
    void push(int val){
        if (full()){
            cout<<"Stack Overflow\n";
            return;
        }
        arr[++top]=val;
    }
    int pop(){
        if (empty()){
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }
    int peek(){
        if (empty()){
            cout<<"Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
};
int main(){
    Stack z;
    int choice, val;
    do{
        cout<<"\nStack Menu\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Peek\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice){
            case 1:
                cout<<"Enter value You wanna push: ";
                cin>>val;
                z.push(val);
                break;
            case 2:
                cout<<z.pop() << " Popped from stack\n";
                break;
            case 3:
                cout<<"Top element is : " << z.peek() << endl;
                break;
            case 4:
                cout<<"Exiting program\n";
                break;
            default:
                cout<<"Worng choice\n";
        }
    }while(choice != 4);
    return 0;
}
