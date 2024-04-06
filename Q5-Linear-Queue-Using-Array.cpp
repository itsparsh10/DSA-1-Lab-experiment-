// Implement Linear Queue ADT using array.
#include <iostream>
using namespace std;
#define max_size 100
class Queue {
    int front,rear,size;
    int array[max_size];
public:
    Queue(){
        front=rear=-1;
        size=0;
    }

    bool empty(){
        return size==0;
    }

    bool full(){
        return size==max_size;
    }

    void enqueue(int item) {
        if (full()){
            cout<<"Queue is full\n";
            return;
        }
        rear=(rear+1)%max_size;
        array[rear]=item;
        size++;
    }

    int dequeue(){
        if (empty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        int item=array[front];
        front=(front+1)%max_size;
        size--;
        return item;
    }

    int peek(){
        if (empty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        return array[front];
    }

    void display(){
        if (empty()){
            cout<<"Queue is empty\n";
            return;
        }
        int i=front;
        while (i!=rear) {
            cout<<array[i]<<" ";
            i=(i + 1)%max_size;
        }
        cout<<array[rear]<<endl;
    }
};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout<<"Queue elements:";
    q.display();

    cout<<"Dequeued element:" <<q.dequeue()<< endl;

    cout<<"Queue elements after dequeue:";
    q.display();

    cout<<"Front element:"<<q.peek()<<endl;

    return 0;
}

