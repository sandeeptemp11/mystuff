#include <bits/stdc++.h>
using namespace std;

class base_class{
    public:
    virtual void fun(){ // reove virtual and observe changes
        cout << "base_class\n";
    }
};

class derived_class: public base_class{
    public:
    void fun(){
        cout << "derived class\n";
    }
};

int main(){
    derived_class child;
    base_class* parent = &child;
    parent->fun();
}
