#include <iostream>
#include <bits/stdc++.h>
#include <numeric>
#include <cmath>
using namespace std;
#define n (int)1e5

// implementation of stack using arrays
// stack is a linear data structure
template <typename t> class myStack{
    t arr[n];
    int top = -1;

    public:
    bool isFull(){
        return top == n;
    }

    bool isEmpty(){
        return top == -1;
    }

    void push(t ele){
        if(!isFull()) arr[++top] = ele;
        // cout << arr[top];
    }

    void pop(){
        if(!isEmpty()) top--;
    }

    t getTop(){
        if(!isEmpty()) return arr[top]; 
    }
    
};

int main(){
    myStack <string> s;
    s.push("sandeep");
    s.push("RAM");
    cout << s.getTop() << "\n";
    s.pop();
    cout << s.getTop() << "\n";
    s.pop();
    cout << s.isEmpty() << "\n";
}
