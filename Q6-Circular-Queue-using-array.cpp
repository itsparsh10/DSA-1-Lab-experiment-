// Implement Circular Queue ADT using array.
#include <iostream>
using namespace std;
#define size 10

class CircularQueue {
private:
    int items[size],front,rear;

public:
    CircularQueue(){
        front=-1;
        rear=-1;
    }
    bool full(){
        if ((front==0 && rear==size-1) || (rear == (front-1) % (size-1))){
            return true;
        }
        return false;
    }
    bool empty() {
        if(front==-1)
            return true;
        else
            return false;
    }
    void enQueue(int element) {
        if (full()){
            cout<<"Queue is full";
        } 
        else{
            if (front == -1) front=0;
            rear= (rear+1) % size;
            items[rear]=element;
            cout<<endl
                 <<"Inserted"<<element<< endl;
        }
    }
    int deQueue() {
        int element;
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return (-1);
        } 
        else{
            element=items[front];
            if(front==rear) {
                front=-1;
                rear=-1;
            } else {
                front=(front+1) % size;
            }
            return (element);
        }
    }

    void displayQueue(){
        if (empty()){
            cout<<"Empty Queue"<<endl;
        } else{
            cout<<"Front -> "<<front<< endl;
            cout<<"Items -> ";
            for(int i=front;i!= rear;i=(i + 1) % size) {
                cout<<items[i]<< " ";
            }
            cout<<items[rear]<<endl;
            cout<<"Rear -> "<<rear<<endl;
        }
    }
};

int main(){
    CircularQueue q;
    q.deQueue();

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);
    q.displayQueue();
    int elements = q.deQueue();

    if (elements != -1)
        cout << "Deleted Element is " << elements << endl;
    q.displayQueue();
    q.enQueue(7);
    q.displayQueue();

    q.enQueue(8);

    return 0;
}
