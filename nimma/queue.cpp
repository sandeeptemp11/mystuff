#include <iostream>
#include <bits/stdc++.h>
using namespace std;
static constexpr int n = 5; // why this is needed

template <typename t> class Queue{
    t arr[n];
    int front = -1;
    int rear = -1;

    public:
    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return (rear+1)%n == front;
    }

    void push(t ele){
        if(!isFull()){
            if(front == -1) front++;
            rear = (rear+1)%n;
            arr[rear] = ele;
        }
    }

    void pop(){
        if(!isEmpty()){
            if(front == rear){
                front = -1;
                rear = -1;
            }else front = (front+1)%n;
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
    Queue <int> q;
    for(int i= 0; i < 5; i++) q.push(i);
    cout << "CHECK1\n";
    cout << q.getFront() << "\n";
    cout << q.getRear() << "\n";
    q.pop();
    q.push(100);

    cout << "\nCHECK2\n";
    cout << q.getFront() << "\n";
    cout << q.getRear() << "\n";
    q.push(220);

    cout << "\nCHECK3\n";
    cout << q.getFront() << "\n";
    cout << q.getRear() << "\n";

    while(!q.isEmpty()) q.pop();
    q.push(100);
    q.push(99);
    cout << "\nCHECK4\n";
    cout << q.getFront() << "\n";
    cout << q.getRear() << "\n";
}
