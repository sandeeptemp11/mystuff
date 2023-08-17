#include <iostream>
using namespace std;
const int n = 5;

template <typename t> class Dequeue{
    t arr[n];
    int front = -1;
    int rear = -1;

    public:
    bool isFull(){
        return (rear+1)%n == front;
    }

    bool isEmpty(){
        return front == -1;
    }

    void pushFront(t ele){
        if(!isFull()){
            if(front == -1){
                front = 0;
                rear = 0;
            }else front = (front-1+n)%n;
            arr[front] = ele;
        }
    }

    void deleteFront(){
        if(!isEmpty()){
            if(front == rear){
                front = -1;
                rear = -1;
            }else front = (front+1)%n;
        }
    }

    void pushBack(t ele){
        if(!isFull()){
            if(front == -1){
                front = 0;
                rear = 0;
            }else rear = (rear+1)%n;
            arr[rear] = ele;
        }
    }

    void deleteBack(){
        if(!isEmpty()){
            if(front == rear){
                front = -1;
                rear = -1;
            }else rear = (rear-1+n)%n;
        }
    }

    t getFront(){
        if(!isEmpty()) return arr[front];
    }

    t getRear(){
        if(!isEmpty()) return arr[rear];
    }
};

int main(){
    Dequeue <int> dq;
    dq.pushFront(100);
    dq.pushFront(2);
    dq.pushFront(3);
    dq.pushBack(-11);
    dq.pushBack(-15);
    dq.pushBack(-15);

    cout << dq.getFront() << "\n";
    dq.deleteBack();
    cout << dq.getRear() << "\n";
    dq.pushFront(55);
    cout << dq.getFront() << "\n";
}
